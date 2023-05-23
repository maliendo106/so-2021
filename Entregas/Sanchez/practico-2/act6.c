#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define MAX_CHAR 1024

int main(int argc,char *argv[]) {
   
    char text [MAX_CHAR];
    int original;
    int copia;
    int n;

    original = open(argv[1], O_RDONLY);
    if(original < 0 ){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    copia = open("archivoCopia.bak", O_RDWR|O_CREAT,0644);
    if(copia < 0){
        printf("No se encontro el archivo");
        return 1;
    }

    while((n = read(original,&text,MAX_CHAR)) > 0)
    {
        write(original,&text,n);
    }

    close(original);
    close(copia);

    return 0;
}