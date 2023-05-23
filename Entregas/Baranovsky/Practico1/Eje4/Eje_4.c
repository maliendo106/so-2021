#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int pid;
    int status;

    pid = fork();

    if (pid == 0){

        printf("Hola soy el hijo, mi pid es: %d\n\n", getpid()); 
     
    } else {

        printf("Hola soy el padre, mi pid es: %d\n\n", getpid()); 
        
        wait(&status);

        if( WIFEXITED(status) ){

            printf("El proceso hijo termino correctamente, con valor de salida: %d\n", WEXITSTATUS(status));

        }else{

            printf("El proceso hijo no termino correctamente, con valor de salida: %d\n", WEXITSTATUS(status));

        }
  
        printf("\nEn este caso, si se termina correctamente, obtendremos un status indicando que no paso nada. En caso de que pusieramos un (sleep) y terminasemos el proceso con kill, obtendriamos un valor distinto de cero (15)\n");

    }

    return 0;
}