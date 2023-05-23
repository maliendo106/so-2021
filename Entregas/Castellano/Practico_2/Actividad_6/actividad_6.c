#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1024


int main(int argc, char *argv[]) {

    int fd, file, aux;
    char buffer[MAX];

    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
         printf("No se encuentra el archivo\n");
         return 1;
    }

    file = open("test.bak", O_RDWR|O_CREAT, 0644);

    while( (aux = read(fd, buffer, MAX)) ) {

         write(file, buffer, aux);
    }

    close(fd);
    close(file);

    return 0;
}