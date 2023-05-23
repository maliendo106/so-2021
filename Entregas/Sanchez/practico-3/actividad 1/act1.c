#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    int archivo;

    while ((archivo = open("test.txt", O_RDONLY)) < 0)
    {
        printf("No se encontro el Archivo.\n");
        sleep(1);
    }

    close(archivo);
    printf("Se encontro el archivo.\n");

    return 0;
}