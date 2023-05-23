#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/*
5. Escriba un programa similar al anterior, pero modificado de modo 
que el hijo quede en espera indefinida, luego desde una terminal envíe 
una señal (por medio del comando kill para que termine y observe el 
comportamiento del status de salida.
Investigue las señales posibles por medio de man 7 signal .
*/

int main()
{
    int pid;
    pid = fork();

    if ( pid == 0 )
    {
        /* hijo */
        printf( " Soy el hijo con PID: %d \n ", getpid() );
        sleep( 999 );
    }
    else
    {
        /* padre */
        int status;

        printf( " Soy el padre con PID: %d \n", getpid() );

        wait(&status);

        if ( WIFSIGNALED( status ) )
        {
            printf( "\n El proceso hijo fue interrumpido por una señal ID: %d ", WTERMSIG( status ) );
        }
        else
        {
            printf( "\n El proceso hijo termino normalmente \n ");
        }
    }
    return 0;
}