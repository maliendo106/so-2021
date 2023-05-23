#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX_POS 350

int main()
{
    int processId;
    int pipes[1];
    int estado1, estado2;
    pipe(pipes);

    if ((processId = fork()) == 0)
    {
        // Hijo 1
        time_t tiempo;
        char *msj;
        // gurado el tiempo
        time(&tiempo);
        msj = ctime(&tiempo);
        //paso por el pipe el msj
        write(pipes[1], msj, strlen(msj));
    }
    else
    {
        if ((processId = fork()) == 0)
        {
            // Hijo 2
            char buffer[MAX_POS];
            read(pipes[0], buffer, MAX_POS);
            printf("Lectura: %s", buffer);
        }
        else
        {
            // En el Padre
            wait(&estado1);
            printf("Estado 1: %d\n", status1);
            wait(&estado1);
            printf("Estado 1: %d\n", status1);
        }
    }
    return 0;
}