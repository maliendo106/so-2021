#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

// Este programa sera el que sobre-escribe el mensaje
int main() {
  int fd;
  char buff[MAX];
  char msg[] = "Chau";

  // access checkea la accesiblidad de un archivo
  if (access("comunicador.txt", F_OK) != 0)
    sleep(1);

  fd = open("comunicador.txt", O_RDWR);
  read(fd, &buff, MAX);
  lseek(fd, 0, SEEK_SET);

  if (strcmp(buff, msg) != 0)
    write(fd, msg, strlen(msg) + 1);

  printf("Mensaje cambiado!\n");

  close(fd);

  return 0;
}