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
  int file = close(open("file",O_CREAT,0644));

  if ((pid = fork()) == 0)
  {
    int file;
    int filelock;
    time_t atime;
    char *mensaje;

    file = open("file", O_WRONLY);
    time(&atime);
    mensaje = ctime(&atime);

    write(file, mensaje, strlen(mensaje));

    close(file);
  }
  else
  {

    if ((pid = fork()) == 0)
    {

      int file;
      time_t atime;
      char buffer[MAX];
      

      file = open("file", O_RDONLY);
      if(file < 0 ){
        printf("No se pudo abrir el archivo");
    }
      while (1)
      {
        
        read(file, buffer, MAX);

        if (strcmp(buffer, "") == 0)
          continue;
        
        printf("Lectura: %s\n", buffer);

        close(file);
        break;
      }
    }
    else
    {
      int status, statusb;
      wait(&status);
      printf("StatusA: %d\n", status);
      wait(&statusb);
      printf("StatusB: %d\n", statusb);
    }
  }
  return 0;
}
