#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX 100

// funcion principal main
int main(int argc, char *argv[]) {

  int fd;
  char buffer[MAX];
  char mensaje[] = "hola como estas";

  
    remove("comunicador.txt");
    fd = open("comunicador.txt", O_RDWR | O_CREAT, 0664);

    write(fd, mensaje, strlen(mensaje) + 1);
    lseek(fd, 0, SEEK_SET);
    printf("ej4_a: %s\n", mensaje);

    while (read(fd, buffer, MAX)) {
        if (strcmp(buffer, mensaje) != 0)
            break;
        lseek(fd, 0, SEEK_SET);
        printf(".\n");
        sleep(3);
    }

    read(fd, buffer, MAX);
    printf("ej4_b: %s\n", buffer );
    close(fd);
  
  return 0;
}