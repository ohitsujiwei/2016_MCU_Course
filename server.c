#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8787);
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("bind error");
        return 1;
    }
    puts("bind done\n");
    listen(socket_desc, 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
    time_t now;
    struct tm *timeinfo;
    time (&now);
    timeinfo = localtime(&now);
    message = asctime(timeinfo);
    write(new_socket, message, strlen(message));
    return 0;
}
