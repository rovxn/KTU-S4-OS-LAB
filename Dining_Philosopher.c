#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;


void *philosopher(void *arg)
{
    int phil_id = *(int *)arg;
    int left_fork = phil_id;
    int right_fork = (phil_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", (phil_id+1));
        sleep(rand() % 3 + 1);  // Thinking

        sem_wait(&mutex);
        sem_wait(&forks[left_fork]);
        sem_wait(&forks[right_fork]);

        printf("Philosopher %d is eating.\n", (phil_id+1));
        sleep(rand() % 3 + 1);  // Eating

        sem_post(&forks[left_fork]);
        sem_post(&forks[right_fork]);
        sem_post(&mutex);
    }
}


int main()
{
    int i;
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        sem_init(&forks[i], 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        pthread_join(philosophers[i], NULL);

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
        sem_destroy(&forks[i]);

    sem_destroy(&mutex);

    return 0;
}
