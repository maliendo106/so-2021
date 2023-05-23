#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
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

int main()
{
    int pid;
    pid = fork();
    int status;

    if (pid == 0)
    {
        /* hijo */
        printf( " Soy el hijo con PID: %d \n ", getpid() );
    }
    else
    {
        /* padre */
        printf( " Soy el padre con PID: %d \n ", getppid() );
        wait( &status );
        
        if ( WIFEXITED( status ) )
        {
            printf( " El proceso hijo termino correctamente, con status: %d \n ", WEXITSTATUS( status ) );
        }
        else
        {
            printf( " El proceso hijo no termino correctamente y su status es de: %d\n", WEXITSTATUS( status ) );
        }
    }
    return 0;
}