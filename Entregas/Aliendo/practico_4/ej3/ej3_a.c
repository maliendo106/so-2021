#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 512

// funcion principal main para el segundo hijo!
int main() {
  
  int fd;
  char bufferer[MAX];
  
  fd = open("pipe", O_RDONLY);

  if (fd != -1) {
    read(fd, buffer, MAX);
    printf("lectura %s", buffer);
  }

  return 0;
  
}