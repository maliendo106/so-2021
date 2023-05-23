/*
3) Cliente-Servidor con pipes sin nombre. Escribiremos un programa que
creara dos hijos los cuales se comunicaran utilizando pipes sin nombre.
Uno de los hijos obtiene la hora del sistema como antes, y envía ese dato
utilizando pipes. El segundo recibe los datos y los muestra por pantalla.
*/

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 150

int main() {
  int pid;
  int p[2];
  pipe(p);

  if ((pid = fork()) == 0) {
      
    // Hijo 1
    time_t ct; //current time
    char *msg;

    time(&ct);
    msg = ctime(&ct);

    write(p[1], msg, strlen(msg));
  } else {

    if ((pid = fork()) == 0) {

      // Hijo 2
      char buff[MAX];
      read(p[0], buff, MAX);
      printf("Chat: %s", buff);

    } 
  }
  return 0;
}