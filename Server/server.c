#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8181
#define BUF_SIZE 600

int main()
{
    int s, c;
    socklen_t addrlen;
    struct sockaddr_in srvr, client;
    char buf[BUF_SIZE];
    const char *data = "HTTP/1.0 200 OK\nServer: httpd v1.0\n\nHello, World!";

    // Zero out the server and client structures
    memset(&srvr, 0, sizeof(srvr));
    memset(&client, 0, sizeof(client));

    // Create socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        perror("Socket creation failed");
        return -1;
    }

    srvr.sin_family = AF_INET;
    srvr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    srvr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(s, (struct sockaddr *)&srvr, sizeof(srvr)) < 0)
    {
        perror("Bind failed");
        close(s);
        return -1;
    }

    // Listen for incoming connections
    if (listen(s, 5) < 0)
    {
        perror("Listen failed");
        close(s);
        return -1;
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming client connections
    addrlen = sizeof(client);
    c = accept(s, (struct sockaddr *)&client, &addrlen);
    if (c < 0)
    {
        perror("Accept failed");
        close(s);
        return -1;
    }

    printf("Connection established with client.\n");

    // Clear buffer and read data from the client
    memset(buf, 0, sizeof(buf));
    ssize_t bytesRead = read(c, buf, sizeof(buf) - 1);
    if (bytesRead < 0)
    {
        perror("Read failed");
        close(c);
        close(s);
        return -1;
    }

    // Send HTTP response
    ssize_t bytesWritten = write(c, data, strlen(data));
    if (bytesWritten < 0)
    {
        perror("Write failed");
        close(c);
        close(s);
        return -1;
    }


    close(c);
    close(s);

    return 0;
}
