#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char *argv[]) {
  char *nombre = argv[1];
  char *copia = strdup(argv[1]);
  copia = strcat(copia, ".bak");
  char buff[MAX];
  int aux;
  int fd_original;
  int fd_copia;

  fd_original = open(nombre, O_RDONLY);
  if (fd_original < 0) {
    printf("No existe el archivo!\n");
    return 0;
  }

  fd_copia = open(copia, O_WRONLY | O_CREAT, 0644);

  while ((aux = read(fd_original, buff, MAX)))
    write(fd_copia, buff, aux);

  close(fd_original);
  close(fd_copia);

  return 0;
}