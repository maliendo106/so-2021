#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 512

// funcion principal main para el primer hijo
int main() {
  
  int fd;
  time_t curtime;
  char *mensaje;

  fd = open("pipe", O_WRONLY);

  if (fd != -1) {

    time(&curtime);

    mensaje = ctime(&curtime);
    write(fd, mensaje, strlen(mensaje));
  }

  return 0;
  
}