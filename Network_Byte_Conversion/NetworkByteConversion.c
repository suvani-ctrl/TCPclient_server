#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    unsigned short host_port = 12345;      
    unsigned long host_address = 0x12345678; 
    unsigned short net_port;
    unsigned long net_address;

    // Convert to network byte order
    net_port = htons(host_port);
    net_address = htonl(host_address);

   
    printf("Host Ordered port: %#x\n", host_port);
    printf("Network Ordered port: %#x\n", net_port);
    printf("Host Ordered address: %#lx\n", host_address);
    printf("Network Ordered address: %#lx\n", net_address);

    return 0;
}
