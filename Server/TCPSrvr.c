#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <strings.h> // For bzero
#include <string.h>  // For strlen

int main() {
    int server_sockFD, client_sockFD;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressLength;

    server_sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockFD == -1) {
        perror("There was an error connecting to the socket");
        exit(1);
    } else {
        printf("Socket: %d\n", server_sockFD);
    }

    // BINDING THE SOCKET -----> STEP 2 <-------------
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(8080);

    if (bind(server_sockFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) != 0) {
        printf("Failed to Bind !\n");
        exit(1);
    } else {
        printf("Bind was successful!\n");
    }

    // LISTENING TO THE SOCKET --------------> STEP 3 <--------------
    if (listen(server_sockFD, 1) != 0) {
        printf("Failed to listen!\n");
        exit(1);
    } else {
        printf("The server is listening for incoming connections\n");
    }

    bzero(&clientAddress, sizeof(clientAddress));
    clientAddressLength = sizeof(clientAddress);
    client_sockFD = accept(server_sockFD, (struct sockaddr *)&clientAddress, &clientAddressLength);
    if (client_sockFD == -1) {
        printf("Failed to accept\n");
        exit(1);
    } else {
        printf("Accepted!\n");
    }

    // Sending a message to the client
    char *msg = "Hello Suvani";
    if (write(client_sockFD, msg, strlen(msg)) == -1) {
        perror("Error sending message to the client");
    } else {
        printf("Message sent: %s\n", msg);
    }

    close(client_sockFD);
    close(server_sockFD);

    return 0;
}
