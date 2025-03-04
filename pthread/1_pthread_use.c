#include <pthread.h>
#include <stdio.h>

/*
pthreads（POSIX Threads）是 POSIX 標準定義的多線程庫，用來支援多線程。
在 C 語言中，可以使用 pthread 來創建、管理和控制線程。

#include <pthread.h>
int pthread_create(pthread_t *thread, 
                   const pthread_attr_t *attr,
                   void *(*start_routine)(void *), 
                   void *arg);
thread：輸出參數，存儲創建的線程 ID。
attr：線程的屬性，通常設為 NULL，表示使用默認設置。
start_routine：每個線程要執行的函數。
arg：傳遞給線程函數的參數。

*/

void *print_message(void *message) {
    printf("%s\n", (char *)message);
    return NULL;
}

int main() {
    pthread_t thread;
    
    const char *message = "Hello from the thread!";
    pthread_create(&thread, NULL, print_message, (void *)message);
    pthread_join(thread, NULL);  // 等待線程執行完畢

    return 0;
}

