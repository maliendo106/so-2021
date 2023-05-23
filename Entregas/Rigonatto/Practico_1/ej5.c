/*
5. Escriba un programa similar al anterior, pero modificado de modo 
que el hijo quede en espera indefinida, luego desde una terminal envíe 
una señal (por medio del comando kill para que termine y observe el 
comportamiento del status de salida.
Investigue las señales posibles por medio de man 7 signal .
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    int status;

    //Hijo
    if(pid == 0){
        printf("PID del proceso hijo desde el proceso hijo -> %d\n", getpid());
        printf("PID del proceso padre desde el proceso hijo -> %d\n", getppid());
        fflush(stdout);
        sleep(999); //despues lo mato desde la consola
        return 0;
        
    //Padre
    }else{ 

        printf("PID del proceso padre desde el proceso padre -> %d\n\n",getpid());
        fflush(stdout);
        wait(&status);
    }
    
    if (WIFSIGNALED(status)){ //returns true if the child process was terminated by a signal.

        printf( "\n\nEl proceso hijo termino debido a una senal \n");
        printf( "ID de la Senal: %d \n", WTERMSIG(status) ); //returns  the  number of the signal that caused the child process to terminate. 
                                                            //This macro should be employed only if WIFSIGNALED returned true.
      
    }else{

        printf( "\n\nEl proceso hijo termino correctamente \n" );
        
    }
    return 0;
}