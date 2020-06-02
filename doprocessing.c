#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void doprocessing(int sock) {
    int i, j, tmp = 0, a, b, c, d, randNum, A, B;
    int e[5040][4];
    char ans[4], client_Num[4], reAB[100], *message;
    
    srand(time(0));
    for (i = 0; i < 10000; i++) {
        a = (i / 1) % 10;
        b = (i / 10) % 10;
        c = (i / 100) % 10;
        d = (i / 1000) % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            e[tmp][0] = d;
            e[tmp][1] = c;
            e[tmp][2] = b;
            e[tmp][3] = a;
            tmp++;
        }
    }
    randNum = (rand() % 5040);
    printf("%d%d%d%d\n", e[randNum][0], e[randNum][1], e[randNum][2], e[randNum][3]);
    sprintf(ans, "%d", e[randNum][0] * 1000 + e[randNum][1] * 100 + e[randNum][2] * 10 + e[randNum][3]);
    while (1) {
        A = 0, B = 0;
        bzero(client_Num, 4);
        read(sock, client_Num, 4);
        for (i = 0; i < 4; i++)
            if (client_Num[i] == ans[i])
                A++;
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (client_Num[i] == ans[j] && i != j)
                    B++;
        if (A == 4) {
            message = "Congratulations! You're answer is Right!";
            write(sock, message, strlen(message) + 1);
            exit(1);
        } 
        else {
            sprintf(reAB, "%dA%dB", A, B);
            write(sock, reAB, strlen(reAB) + 1);
        }
    }
}
