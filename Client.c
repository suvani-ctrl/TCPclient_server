#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IP "X.X.X.X"  //could be anything honestly <3
#define PORT 80          

int main() {    
    int s;
    struct sockaddr_in sock;
    char buff[600];
    const char *data = "HEAD / HTTP/1.0\r\n\r\n"; 

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("Socket creation error");
        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PORT);
    sock.sin_addr.s_addr = inet_addr(IP);


    if (connect(s, (struct sockaddr *)&sock, sizeof(sock)) < 0) {
        perror("Connection Error");
        close(s);
        return -1;
    }

    printf("Connected to the server successfully.\n");


    if (write(s, data, strlen(data)) < 0) {
        perror("Write Error");
        close(s);
        return -1;
    }

    int bytes_received = read(s, buff, sizeof(buff) - 1);
    if (bytes_received < 0) {
        perror("Read Error");
        close(s);
        return -1;
    }

    buff[bytes_received] = '\0';
    printf("\nServer response:\n%s\n", buff);

    close(s);
    return 0;
}



