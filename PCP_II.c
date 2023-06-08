#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

#define SIZE 5
int in=0,out=0,buffer[SIZE],count=0;

sem_t full,empty,mutex; 

pthread_t P,C;

void *producer(void *arg){
	
	while(1){
		
	int i;
    	
        sem_wait(&empty);
        sem_wait(&mutex);
        
        
	i=rand()%100;
        buffer[in] = i;
        printf("Producer produced item %d\n", buffer[in]);
        in = (in + 1) % SIZE;
        count++;
	//sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        
    
	}

}

void *consumer(void *arg){
	
	while(1){
		
	int i;
    	
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumer consumed item %d\n", item);
        out = (out + 1) % SIZE;
        count--;
	sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
        
    
	}

}

void main(){
	
	 sem_init(&empty,0,SIZE);
	 sem_init(&full,0,0);
	 sem_init(&mutex,0,1);
	
	
	pthread_create(&P, NULL, producer, NULL);
    	pthread_create(&C, NULL, consumer, NULL);
	
	pthread_join(P, NULL);
    	//pthread_join(C, NULL);
}
