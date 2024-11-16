#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main() {
    int server_sockFD, client_sockFD;
    struct sockaddr_in serverAddress, clientAddress;
    int ClientAddressLength;

    server_sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockFD < 0) {
        perror("Socket not created");
        exit(1);
    } else {
        printf("Socket: %d\n", server_sockFD);
    }

    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sockFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Binding failed");
        close(server_sockFD);
        exit(1);
    }

    if (listen(server_sockFD, 1) != 0) {
        perror("Listen failed");
        close(server_sockFD);
        exit(1);
    } else {
        printf("The server is listening :-)\n");
    }

    bzero(&clientAddress, sizeof(clientAddress));
    ClientAddressLength = sizeof(clientAddress);

    client_sockFD = accept(server_sockFD, (struct sockaddr*)&clientAddress, &ClientAddressLength);
    if (client_sockFD == -1) {
        printf("Failed to accept!\n");
        exit(1);
    } else {
        printf("Accepted!\n");
    }

    char msg[] = "Hi Suvani <3";
    write(client_sockFD, msg, strlen(msg));
    printf("Sent: %s\n", msg);

    close(client_sockFD);
    close(server_sockFD);

    return 0;
}
                                   
