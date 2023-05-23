#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main() {
  // buff es el buffer, su tamanio es de 1 porque se leera char a char
  char buff[MAX];
  int fd;
  int n;

  // Crea el archivo
  system("ls -l > ls.txt");

  // fd es un file descriptor, y abre el archivo
  fd = open("ls.txt", O_RDONLY);

  if (fd < 0) {
    printf("No existe el archivo!\n");
    return 0;
  }

  // read devuelve la cantidad de bytes leidos. si es 0, significa que se llego
  // al final del archivo
  while ((n = read(fd, buff, MAX)))
    printf("%s", buff);

  close(fd);

  return 0;
}