#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_POS 10

int main()
{
    char buff[MAX_POS];
    int archivo;

    char msg[] = "Hola Proceso";

    remove("comunicador.txt");
    archivo = open("comunicador.txt", O_RDWR | O_CREAT, 0664);

    write(archivo, msg, strlen(msg) + 1);
    lseek(archivo, 0, SEEK_SET);

    while (read(archivo, &buff, MAX_POS))
    {
        if (strcmp(buff, msg) != 0)
            break;
        lseek(archivo, 0, SEEK_SET);
        printf("Escuchando...\n");
        sleep(1);
    }
    close(archivo);

    printf("Nuevo mensaje\n");

    return 0;
}