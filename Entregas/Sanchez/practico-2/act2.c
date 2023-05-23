#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CHAR 1024

int main() {
  // En text se lee char por char 
  char text[MAX_CHAR];
  int fileDescriptor;
  int n;

  // Crea el archivo
  system("ls -l > test.txt");

  
  fileDescriptor = open("test.txt", O_RDONLY);

  if (fd < 0) {
    printf("No existe el archivo!\n");
    return 0;
  }

  // read devuelve la cantidad de chars leidos si devuelve 0 se deja de leer
  while ((n = read(fileDescriptor, text, MAX_CHAR)))
    printf("%s", text);

  close(fd);

  return 0;
}