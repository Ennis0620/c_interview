#include <stdio.h>
#include <pthread.h>

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, NULL, NULL);
    pthread_join(tid, NULL);
    return 0;
}