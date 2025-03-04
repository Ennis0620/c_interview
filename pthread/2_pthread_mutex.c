#include <pthread.h>
#include <stdio.h>

/*
在多線程程式中，可能會有多個線程同時訪問共享資源，這會導致race condition。
為了避免這種情況，我們可以使用互斥鎖（mutex）來保護共享資源，確保同一時間只有一個線程可以訪問它。

創建互斥鎖
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

使用互斥鎖：
pthread_mutex_lock()：獲取鎖。
pthread_mutex_unlock()：釋放鎖。

*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *increment(void *arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Counter: %d\n", counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[5];
    /*
    五個線程共享同一個 counter 變數。
    我們使用互斥鎖來保證每次只有一個線程可以操作這個變數。
    */
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Counter: %d\n", counter);
    //完成線程同步後，應該銷毀互斥鎖。使用 pthread_mutex_destroy() 函數來銷毀互斥鎖
    pthread_mutex_destroy(&mutex);
    return 0;
}

