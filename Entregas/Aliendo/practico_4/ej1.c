#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 1024

// funcion principal main
int main() {
  int pid;

  remove("b-inout");
  close(creat("b-inout", 0644));

  // para el primero hijo
  if ((pid = fork()) == 0) {

    int fd, rflock;
    time_t curtime;
    char *mensaje;

    fd = open("b-inout", O_WRONLY);
    time(&curtime);
    mensaje = ctime(&curtime);
    write(fd, mensaje, strlen(mensaje));
    flock(fd, LOCK_UN);

    close(fd);

  } else{

    // para el segundo hijo
    if ((pid = fork()) == 0) {
     
      int fd, rflock;
      char buffer[MAX];
      char *curtime_str;
      time_t curtime;

      fd = open("b-inout", O_RDONLY);
      while (1) {

        read(fd, buffer, MAX);

        if (strcmp(buffer, "") == 0) {

          flock(fd, LOCK_UN);
          continue;
        }

        printf("Lectura: %s\n", buffer);

        close(fd);
        break;
      }
    } else {

      int status1, status2;
      wait(&status1);
      printf("-status1 %d\n", status1);
      wait(&status2);
      printf("-status2 %d\n", status1);
    }

  }

  return 0;
  
}
