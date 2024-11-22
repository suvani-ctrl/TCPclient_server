#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define Buf_size 1000

void error_handler(char *message)
{
    fputs(message, stderr);
    exit(1);
}

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    char message_buffer[Buf_size];
    char message[1000];
    int str_len, i;

    struct sockaddr_in server_adr;
    struct sockaddr_in client_adr;
    socklen_t client_addresss_size;

    if (argc != 2) {
        perror("Usage: <port number>");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handler("socket() error");
    }

    memset(&server_adr, 0, sizeof(server_adr));

    server_adr.sin_family = AF_INET;
    server_adr.sin_port = htons(atoi(argv[1]));
    server_adr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_adr, sizeof(server_adr)) == -1) {
        error_handler("bind() error");
    }

    if (listen(server_socket, 5) == -1) {
        error_handler("listen() error");
    }

    client_addresss_size = sizeof(client_adr);

    for (i = 0; i < 5; i++) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_adr, &client_addresss_size);
        if (client_socket == -1) {
            error_handler("accept() error");
        } else {
            printf("Connection successfully established with client!\n");

            while ((str_len = read(client_socket, message_buffer, Buf_size)) != 0) {
                write(client_socket, message_buffer, str_len);
            }

            close(client_socket);
        }
    }

    close(server_socket);

    return 0;
}
