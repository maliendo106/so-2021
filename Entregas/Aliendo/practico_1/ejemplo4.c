#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    int pid;
    int status;
    pid = fork();

    if ( pid == 0 ) {
        // hijo
        printf("hijo, llamada getpid: %d\n\n", getpid() );

    } else {
        // padre
        printf("padre, llamada getpid: %d\n", getpid() );

        wait(&status);

        if ( WIFEXITED(status) ) {
             printf("El hijo termino normalmente con valor de salida: %d\n", WEXITSTATUS(status));
         } else {
             printf("El hijo NO termino normalmente con valor de salida: %d\n", WEXITSTATUS(status));
        }

    }

    
    return 0;
    }