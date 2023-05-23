#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 1400

int main(int argc,char *argv[]) {

  int file;
  char buffer [MAX];
  char mensaje[] = "Todo bien";

  file = open("File.txt", O_RDWR);

  read(file, buffer, MAX);

  lseek(file, 0, SEEK_SET);

  write(file, mensaje, strlen(mensaje) + 1);

  printf("Respuesta enviada!\n");

  close(file);
  

  return 0;

}