#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 1400

int main()
{
      int file;
      time_t atime;
      char *mensaje;
      if(open("pipeNamed", O_WRONLY) != -1){
        time(&atime);
        mensaje = ctime(&atime);
        write(file, mensaje, strlen(mensaje));
      }
      
  return 0;
}
