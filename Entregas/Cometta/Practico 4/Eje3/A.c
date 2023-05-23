#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 1024

int main(){
    
  // Hijo 1
  int fd;
  time_t ct; // tiempo actual
  char *msj;

  fd = open("Pipe", O_WRONLY);
  
  if (fd != -1){
    time(&ct);
    msj = ctime(&ct);
    write(fd, msj, strlen(msj));
  }

  return 0;
}
