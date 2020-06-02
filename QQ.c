#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, pid, status = 0;
    
    for (i = 1; i <= 3; i++) {
        pid = fork();
        if (pid != 0) {
            printf("I'm parent, pid=%d, child pid=%d\n", getpid(), pid);
            pid = wait(&status);
        }
        else {
            printf("I'm child, pid=%d, parent pid=%d\n", getpid(), getppid());
            exit(status);
        }
    }
    
    return 0;
}
