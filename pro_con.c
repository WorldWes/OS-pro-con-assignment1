#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include "pro_con.h"

int main()
{   
    int name[2] = {1,2}; //For adding a label to the producers and consumers
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    pthread_t pro[2],con[2];
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < 2; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&name[i]);
    }
    for(int i = 0; i < 2; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&name[i]);
    }

    for(int i = 0; i < 2; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 2; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    printf("Done.\n");
    return 0;
}