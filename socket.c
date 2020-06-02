#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/*
struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

struct in_addr {
    unsigned long s_addr;
};

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
}
*/

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr("120.96.82.30");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }
    puts("Connected");
    
    return 0;
}
