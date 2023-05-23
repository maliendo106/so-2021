#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_POS 10


int main() {
  int archivo;
  char buff[MAX_POS];
  char msg[] = "Hola otro proceso";


  if (access("comunicador.txt", F_OK) != 0){
      sleep(3);
  }

  archivo = open("comunicador.txt", O_RDWR);
  read(archivo, &buff, MAX_POS);
  lseek(archivo, 0, SEEK_SET);

  if (strcmp(buff, msg) != 0){
      write(archivo, msg, strlen(msg) + 1);
  }
    

  printf("Nuevo mensaje\n");

  close(archivo);

  return 0;
}