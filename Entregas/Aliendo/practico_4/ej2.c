#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#define MAX 512

// funcion principal main
int main() {
  int pid;
  int p[2];
  pipe(p);

// para el primero hijo
  if ((pid = fork()) == 0) {

    time_t curtime;
    char *mensaje;

    time(&curtime);
    mensaje = ctime(&curtime);
    write(p[1], mensaje, strlen(mensaje));

  } else {

    // para el segundo hijo
    if ((pid = fork()) == 0) {

      char buff[MAX];
      read(p[0], buff, MAX);
      printf("Lectura: %s", buff);
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
