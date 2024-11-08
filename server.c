#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8181

int main()
{
    int s, c;
    socklen_t addrlen;
    struct sockaddr_in srvr, client;
    char buf[600];
    const char *data = "HTTP/1.0 200 OK\nServer: httpd v1.0\n\nHello, World!";
    
    memset(&srvr, 0, sizeof(srvr));
    memset(&client, 0, sizeof(client));
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        printf("Socket Failed\n");
        return -1;
    }
    
    srvr.sin_family = AF_INET;
    srvr.sin_addr.s_addr = INADDR_ANY;
    srvr.sin_port = htons(PORT);
    
    if (bind(s, (struct sockaddr *)&srvr, sizeof(srvr)) < 0)
    {
        printf("bind() failed\n");
        return -1;
    }
    
    if (listen(s, 5) < 0)
    {
        printf("listen() failed\n");
        return -1;
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    addrlen = sizeof(client);
    c = accept(s, (struct sockaddr *)&client, &addrlen);
    if (c < 0)
    {
        printf("accept() failed\n");
        return -1;
    }

    printf("Connection accepted\n");
    
    read(c, buf, sizeof(buf));
    
    write(c, data, strlen(data));
    
    close(c);
    close(s);
    
    return 0;
}
