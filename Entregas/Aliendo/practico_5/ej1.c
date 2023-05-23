#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>   // para trabajar con hilos
#include <semaphore.h> // para trabajar con semaforos
#define N 10

// Prototipo de funciones
static void *productor(void *arg);
static void *consumidor(void *arg);

static int buffer = 0; // Variable compartida
static int valor_mutex, valor_empty, valor_full;

// Declaro los semaforos
sem_t mutex;
sem_t empty;
sem_t full;

// Funcion principal main
int main()
{

    pthread_t thread_1, thread_2; // se inicializan los hilos

    sem_init(&mutex, 0, 1); // inicializo semaforo en 1
    sem_init(&empty, 0, N); //                     en N
    sem_init(&full, 0, 0);  //                     en 0

    pthread_create(&thread_1, NULL, *productor, NULL);  // se crea el primer hilo
    pthread_create(&thread_2, NULL, *consumidor, NULL); // se crea el segundo hilo

    pthread_join(thread_1, NULL); // espera a que terminen los hilos
    pthread_join(thread_2, NULL);

    printf("valor de buffer: %d\n", buffer);
    return 0;
}

// Funcion productor
static void *productor(void *arg)
{

    while (1)
    {
        if (sem_getvalue(&full, &valor_full) <= 0)  // produce cuando el buffer está vacío
        {

            sem_wait(&empty); // decrementa el valor de empty
            sem_wait(&mutex); // entra a la region critica

            sleep(1);

            buffer++; // aquí se produce
            printf("produciendo -> valor de buffer: %d\n", buffer);

            sem_getvalue(&mutex, &valor_mutex);
            sem_getvalue(&empty, &valor_empty);
            sem_getvalue(&full, &valor_full);
            printf("mutex: %d\tempty: %d\tfull: %d\n", valor_mutex, valor_empty, valor_full);

            sem_post(&mutex); // sale de la region critica
            sem_post(&full);  // incrementa el valor de full
        }
    }
}

// Funcion consumidor
static void *consumidor(void *arg)
{

    while (1)
    {

        if (sem_getvalue(&empty, &valor_empty) <= 0)  // consume cuando el buffer está lleno
        {

            sem_wait(&full);  // decrementa el valor de full
            sem_wait(&mutex); // entra en la region critica

            sleep(1);

            buffer--; // aquí se consume
            printf("consumiendo -> valor de buffer: %d\n", buffer);

            sem_getvalue(&mutex, &valor_mutex);
            sem_getvalue(&empty, &valor_empty);
            sem_getvalue(&full, &valor_full);
            printf("mutex: %d\tempty: %d\tfull: %d\n", valor_mutex, valor_empty, valor_full);

            sem_post(&mutex); // sale de la region critica
            sem_post(&empty); // incrementa el valor de empty
        }
    }
}