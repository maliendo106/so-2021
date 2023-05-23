#include <sys/file.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1400

int main()
{
  int pid;
  int pipe[2];
  int status, statusb;
  pipe(pipe);

  if ((pid = fork()) == 0)
  {
    time_t atime;
    char *mensaje;
    time(&atime);
    mensaje = ctime(&atime);
    write(pipe[1], msg, strlen(msg));
  }
  else
  {
    if ((pid = fork()) == 0)
    {
      time_t atime;
      char buffer[MAX];
      read(pipe[0], buffer, MAX);
      printf("Contenido: %s", buffer);
      }
    
    else
    {
      wait(&status);
      printf("El Status A resulta: %d\n", status);
      wait(&statusb);
      printf("El Status B resulta: %d\n", statusb);
    }
  }
  return 0;
}
