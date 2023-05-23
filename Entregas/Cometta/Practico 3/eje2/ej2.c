#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 1

int main (int argc, int *argv[]){

    int file;
    char buffer[MAX];

    if ((file = open ("test.txt",O_RDONLY)) < 0){
        printf("El archivo no existe, intente de nuevo...\n");
        exit(1);
    }
    
    read(file, buffer,1);

    while ((strcmp(buffer,"1")) == 0){

        printf("Hay un 1, prosigo hasta que haya un 0.\n");
        fflush(stdout);
        lseek(file, 0, SEEK_SET); //Reseteamos la posicion de la lectura.
        read(file, buffer, 1);
        sleep(1);

    }

    printf("Se encontro un 0, finaliza...\n");
    close(file);
    return 0;



}