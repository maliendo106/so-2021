#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 15

int main() {
  
  int fd;
  char buff[MAX];
  char mensaje[] = "Esperando";

  remove("comunicador.txt");

  fd = open("comunicador.txt", O_RDWR | O_CREAT, 0664);
  if (fd == -1){
     printf("No se creo el archivo");
  } 
  
  write(fd, mensaje, strlen(mensaje) + 1);
  lseek(fd, 0, SEEK_SET);

  while (read(fd, &buff, MAX)) {
    if (strcmp(buff, mensaje) != 0)
      break;
    lseek(fd, 0, SEEK_SET);
    printf("Esperando!\n");
    sleep(1);
  }
  close(fd);

  printf("El mensaje cambio!\n");

  return 0;
}