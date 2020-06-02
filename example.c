#include <pthread.h>
#include <stdio.h>

void thread(void) {
    int i;
    for (i = 0; i < 13; i++) {
        printf("This is a pthreaed.\n");
        sleep(1);
    }
}

int main(void) {
    pthread_t id;
    int i, ret;

    ret = pthread_create(&id, NULL, (void *)thread, NULL);
    if (ret != 0) {
        printf("Create pthread error!\n");
        exit(1);
    }
    for (i = 0; i < 13; i++) {
        printf("This is the main process.\n");
        sleep(2);
    }
    pthread_join(id, NULL);

    return 0;
}
