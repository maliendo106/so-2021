#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int status;
    
    int pid;
    pid = fork();

    if (pid == 0)
    {
        // ---> hijo <---
        printf("proceso hijo, llamada getpid: %d\n\n", getpid());
        fflush(stdout);
        sleep(999); //  Lo dejo esperando y luego kill() por consola
    }
    else
    {
        //---> padre <---
        printf("proceso padre, llamada getpid: %d\n", getpid());

        wait(&status);

        if (WIFEXITED(status)) // devuelve verdadero si el proceso hijo es terminado 
        {
            printf("el proceso hijo termino NORMALMENTE y su valor de salida es: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("el proceso hijo termino ANORMALMENTE con valor de salida: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}