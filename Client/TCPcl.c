///client pov
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int client_sockFD;
    struct sockaddr_in serverAddress;


    client_sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockFD == -1) {
        perror("Error creating socket");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost


    if (connect(client_sockFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) != 0) {
        perror("Connection failed");
        close(client_sockFD);
        exit(1);
    }

    printf("Connected to the server\n");


    char buffer[1024] = {0};
    read(client_sockFD, buffer, sizeof(buffer));
    printf("Message from server: %s\n", buffer);


    close(client_sockFD);
    return 0;
}
