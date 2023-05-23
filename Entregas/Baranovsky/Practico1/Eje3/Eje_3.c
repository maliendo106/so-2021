#include <stdio.h>

int main(){

    int pid;

    pid = fork();

    if (pid == 0){

        printf("Hola soy el hijo, mi pid es: %d\n\n", getpid()); 
        printf("Hola soy el hijo, el pid de mi padre es: %d\n\n", getppid()); 

    } else {

        printf("Hola soy el padre, mi pid es: %d\n\n", getpid()); 
        sleep(1);

    }
    
    return 0;
}