#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 15


int main() {
  int fd;
  char buff[MAX];
  char msg[] = "Listo";

  fd = open("comunicador.txt", O_RDWR);
  read(fd, &buff, MAX);
  lseek(fd, 0, SEEK_SET);

  if (strcmp(buff, msg) != 0)
    write(fd, msg, strlen(msg) + 1);

  printf("Se cambio el mensaje\n");

  close(fd);

  return 0;
}