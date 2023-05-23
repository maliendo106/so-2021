#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_POS 1

int main(int argc, char *argv[])
{
    int archivo;
    char buffer[MAX_POS];

    if ((archivo = open("test.txt", O_RDONLY)) < 0)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }
    else
    {
        read(archivo, buffer, MAX_POS);

        while (strcmp(buffer, "1") == 0)
        {
            printf("Entra un 1 se sigue ...\n");
            fflush(stdout);
            lseek(archivo, 0, SEEK_SET);
            read(archivo, buffer, MAX_POS);
            sleep(1);
        }
        close(archivo);
        printf("Se encontro un 0. Terminando, \n");
    }
    return 0;
}