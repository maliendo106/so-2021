#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define Max 1400

int main(int argc,char *argv[]) {
    
    int file;
    int file2;
    char buffer [Max];
    int numbyte;

    file = open(argv[1], O_RDONLY);
    if(file < 0 ){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    file2 = open("FileCopy.bak", O_RDWR|O_CREAT,0644);
    if(file2 < 0){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    while((numbyte = read(file,&buffer,Max)) > 0)
    {
        write(file2,&buffer,numbyte);
    }

    close(file);
    close(file2);

    return 0;
}