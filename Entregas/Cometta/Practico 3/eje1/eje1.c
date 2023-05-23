#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]){

    int file; //la funcion open me devuelve un 1 o un -1 si abrio o cerro por eso el int.
    while ((file = open(argv[1], O_RDONLY)) < 0){    
        printf("No existe el archivo\n\n");
        sleep(1);
    }

    printf("El archivo existe\n\n");
    
    close(file);

    return 0;
}