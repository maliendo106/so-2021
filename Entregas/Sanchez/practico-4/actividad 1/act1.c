#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX_POS 150

int main()
{
    int processId;

    remove("b-inout");
    close(creat("b-inout", 0644));
    remove("a-inout");
    close(creat("a-inout", 0644));

    if ((processId = fork()) == 0)
    {
        // proceso hijo 1
        int archivoLectura, archivoEscritura, rflock;
        time_t tiempo;
        char *msg;

        // guardo el tiempo
        time(&tiempo);
        msg = ctime(&tiempo);
        //abro archivos
        archivoEscritura = open("b-inout", O_WRONLY);
        archivoLectura = open("a-inout", O_RDONLY);

        while ((rflock = flock(archivoEscritura, LOCK_EX)) != 0)  {}
      
        write(archivoEscritura, msg, strlen(msg));

        flock(archivoEscritura, LOCK_UN);
        //cierro archivos
        close(archivoEscritura);
        close(archivoLectura);
    }
    else
    {
        if ((processId = fork()) == 0)
        {

            // proceso hijo 2
            int archivoEscritura, archivoLectura, rflock;
            char buffer[MAX_POS];

            //abro archivos
            archivoLectura = open("b-inout", O_RDONLY);
            archivoEscritura = open("a-inout", O_WRONLY);
            while (1)
            {
                while ((rflock = flock(archivoLectura, LOCK_EX)) != 0){}
                
                read(archivoLectura, buffer, MAX_POS);

                if (strcmp(buffer, "") == 0)
                {

                    flock(archivoLectura, LOCK_UN);
                    continue;
                }

                printf("b-inout: %s\n", buffer);
                //cierro archivos
                close(archivoEscritura);
                close(archivoLectura);
                break;
            }
        }
        else
        {
            int statHijo1, statHijo2;

            wait(&statHijo1);
            printf("Estado hijo 1: %d\n", statusHijo1);

            wait(&statHijo2);
            printf("Estado hijo 2: %d\n", statusHijo2);
        }
    }
    return 0;
}