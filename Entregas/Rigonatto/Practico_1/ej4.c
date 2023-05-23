/*
4. Escriba un programa en el cual creamos un proceso y configuramos 
al proceso “padre” para que espere, por medio de la llamada wait() , 
a que termine su hijo antes de proseguir, luego de lo cual debe 
reportar el status de salida del proceso hijo. 
Use la llamada wait() . Se la debe invocar como

...
wait(&STATUS);
...

Use el status de salida, analícelo por medio de las funciones macro 
definidas en la página de manual de la llamada wait() .
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    int status;

    if(pid == 0){//Hijo

        printf( "PID del proceso hijo desde el proceso hijo -> %d \n", getpid() );
        printf( "PID del proceso padre desde el proceso hijo -> %d \n", getppid() );
        fflush(stdout);
        return 0;

    }else{ //Padre

        printf( "PID del proceso padre desde el proceso padre -> %d \n\n", getpid()) ;
        fflush( stdout );
        wait( &status );
    }

    if (WIFEXITED(status)){ //returns true if the child terminated normally

        printf( "\n\nEl proceso hijo termino correctamente \n");
        printf( "Status: %d \n", WEXITSTATUS(status) ); //returns  the exit status of the child. This macro should be employed only if WIFEXITED returned true.
      
    }else{
        printf( "\n\nEl proceso hijo termino incorrectamente \n" );
        
    }
    
    return 0;
}