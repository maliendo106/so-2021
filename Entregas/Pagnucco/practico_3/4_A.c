#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

// Este programa sera el que espera que el mensaje cambie.
int main() {
  int fd;
  char buff[MAX];
  char msg[] = "Hola";

  remove("comunicador.txt");
  fd = open("comunicador.txt", O_RDWR | O_CREAT, 0664);
  write(fd, msg, strlen(msg) + 1);
  lseek(fd, 0, SEEK_SET);

  while (read(fd, &buff, MAX)) {
    if (strcmp(buff, msg) != 0)
      break;
    lseek(fd, 0, SEEK_SET);
    printf("Esperando!\n");
    sleep(1);
  }
  close(fd);

  printf("El mensaje cambio!\n");

  return 0;
}
