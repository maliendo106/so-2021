#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 10

// funcion principal main
int main() {
  int fd;
  char buffer[MAX];
  char mensaje[] = "todo bien y vos";

  if (access("comunicador.txt", F_OK) != 0){
      sleep(3);
  }

  fd = open("comunicador.txt", O_RDWR);
  read(fd, &buffer, MAX);
  lseek(fd, 0, SEEK_SET);

  if (strcmp(buffer, mensaje) != 0){
      write(fd, mensaje, strlen(mensaje) + 1);
  }
    
  printf("Mensaje cambiado!\n");
  close(fd);

  return 0;
}