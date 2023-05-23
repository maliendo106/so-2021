#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/*
3. Escriba un programa similar al anterior, de modo que cada proceso 
obtenga su propio numero de proceso y el de su padre; a continuación 
imprima el resultado. Estudie y utilice las llamadas getpid() y getppid().
*/

int main()
{
    int pid;
    pid = fork();

    if ( pid == 0 )
    {
        /* hijo */
        printf( " Soy el hijo con PID: %d \n ", getpid() );
        printf( " El PID del padre: %d \n ", getppid() );
    }
    else
    {
        /* padre */
        printf( " Soy el padre con PID: %d \n", getppid() );
        
        sleep(1);
    }
    return 0;
}