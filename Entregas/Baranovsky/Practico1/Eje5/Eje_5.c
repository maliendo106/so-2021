#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int pid;
    int status;

    pid = fork();

    if (pid == 0){

        printf("Hola soy el hijo, mi pid es: %d\n\n", getpid()); 
        
        sleep(800);

    } else {

        printf("Hola soy el padre, mi pid es: %d\n\n", getpid()); 
        
        wait(&status);

        if( WIFEXITED(status) ){

            printf("El proceso hijo termino correctamente, con valor de salida: %d\n", WEXITSTATUS(status));

        }else{

            printf("El proceso hijo no termino correctamente, debido a una interrupcion mediante la operacion (kill), con valor de salida: %d  \n ", WTERMSIG(status));

        }
  
    }
    

    return 0;
}