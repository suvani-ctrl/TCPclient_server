#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connection_status < 0) {
        perror("Error while connecting to the server");
        close(client_socket);
        exit(1);
    }

    char msg[256];
    recv(client_socket, &msg, sizeof(msg), 0);

    printf("Connected to the server successfully.\n");
    printf("The msg sent was %s\n", msg);
    close(client_socket);
    return 0;
}
