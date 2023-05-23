// ! NO ANDA

#define LOOPS 20
#define N 100 /* number of slots in the buffer */
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static int buffer = 0;

static void producer(sem_t* mutex, sem_t* empty, sem_t* full) {
  for (int i = LOOPS; i > 0; i--) {
    sem_wait(empty); /* decrement empty count */
    sem_wait(mutex); /* enter critical region */
    buffer++;        /* put new item in buffer */
    printf("+ Quedan %d items en el buffer\n",
           buffer); /* do something with the item */

    int mr, er, fr;
    sem_getvalue(mutex, &mr);
    sem_getvalue(empty, &er);
    sem_getvalue(full, &fr);
    printf("+ [%d, %d, %d]\n", mr, er, fr);

    sem_post(mutex); /* leave critical region */
    sem_post(full);  /* increment count of full slots */

    fflush(stdout);
    usleep(200000 + rand() % 800000);
  }
}

static void consumer(sem_t* mutex, sem_t* empty, sem_t* full) {
  for (int i = LOOPS; i > 0; i--) {
    sem_wait(full);  /* decrement full count */
    sem_wait(mutex); /* enter critical region */
    buffer--;        /* take item from buffer */
    printf("- Quedan %d items en el buffer\n",
           buffer); /* do something with the item */

    int mr, er, fr;
    sem_getvalue(mutex, &mr);
    sem_getvalue(empty, &er);
    sem_getvalue(full, &fr);
    printf("- [%d, %d, %d]\n", mr, er, fr);

    sem_post(mutex); /* leave critical region */
    sem_post(empty); /* increment count of empty slots */

    fflush(stdout);
    usleep(200000 + rand() % 800000);
  }
}

int main() {
  sem_t *mutex; /* controls access to critical region */
  sem_t *empty; /* counts empty buffer slots */
  sem_t *full;  /* counts full buffer slots */

  mutex = sem_open("mutex", O_CREAT, 0644, 1);
  empty = sem_open("empty", O_CREAT, 0644, N);
  full = sem_open("full", O_CREAT, 0644, 0);

  int pid = fork();
  if (pid == 0) {
    /* hijo */
    producer(mutex, empty, full);
  } else {
    /* padre */
    consumer(mutex, empty, full);
  }
  return 0;
}