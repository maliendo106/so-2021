#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // para trabajar con hilos
#include <semaphore.h> // para trabajar con semaforos
#define N 10000

// Prototipo de funciones
static void *producir(void* arg);
static void *consumir(void* arg);

// Variable compartida
static int contador = 0;

// Declaro el semaforo
sem_t semaforo;

// Funcion principal main
int main(){

    pthread_t thread_1, thread_2; // se inicializan los hilos

    sem_init(&semaforo, 0, 1); // inicializo el semaforo en 1

    pthread_create(&thread_1, NULL, *producir, NULL); // se crea el primer hilo 
    pthread_create(&thread_2, NULL, *consumir, NULL); // se crea el segundo hilo 

    pthread_join(thread_1, NULL); // espera a que terminen los hilos
    pthread_join(thread_2, NULL);

    printf("valor de contador: %d\n", contador);
    return 0;
}

// Funcion producir
static void *producir(void* arg){

    for(int i = 0; i < N; i++){

        sem_wait(&semaforo); // decrementa el valor del semaforo
        contador++;  // produce
        sem_post(&semaforo); //incrementa el semaforo
    }
}

// Funcion consumir
static void *consumir(void* arg){

    for(int i = 0; i < N; i++){

        sem_wait(&semaforo);
        contador--;  // consume
        sem_post(&semaforo);
    }
}