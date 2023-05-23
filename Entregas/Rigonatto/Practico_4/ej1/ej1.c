/*
(1) Cliente-Servidor con archivos. Exploraremos la posibilidad de "comunicar" 
dos procesos mediante archivos externos. Escriba un programa que "cree" dos
archivos, a-inout y b-inout. Luego deberá crear dos hijos, cada hijo deberá 
abrir los archivos PERO de modo que el primer hijo abra "a" para lectura y 
"b" para escritura, en cambio el segundo abrira "a" para escritura y "b"
para lectura. Una vez realizado esto el primer hijo debera obtener la hora
del sistema (usando ctime()), escribira esta informacion en "b", cuando esto
ocurra, el segundo proceso hijo obtendra a su vez la hora y la leerra de 
"b", y la mostrara por pantalla. Al finalizar ambos procesos hijos
el padre deberá reportar el estado de terminacion.
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 150

int main() {
  int pid;

  remove("b-inout");
  close(creat("b-inout", 0644));

  remove("a-inout");
  close(creat("a-inout", 0644));

  if ((pid = fork()) == 0) 
  {
    // hijo 1 
    int fdbLectura, fdbEscritura, rflock;
    time_t ct; //current time
    char *msg; //message

    fdbEscritura = open("b-inout", O_WRONLY);
    fdbLectura = open("a-inout", O_RDONLY);
    while ((rflock = flock(fdbEscritura, LOCK_EX)) != 0) {
    }

    time(&ct);
    msg = ctime(&ct);

    write(fdbEscritura, msg, strlen(msg));

    flock(fdbEscritura, LOCK_UN);
    close(fdbEscritura);
    close(fdbLectura);
  } else {

    if ((pid = fork()) == 0) {

      // hijo 2 
      int fdbEscritura, fdbLectura, rflock;
      char buff[MAX];

      fdbLectura = open("b-inout", O_RDONLY);
      fdbEscritura = open("a-inout", O_WRONLY);
      while (1) {
        while ((rflock = flock(fdbLectura, LOCK_EX)) != 0) {
        }

        read(fdbLectura, buff, MAX);

        if (strcmp(buff, "") == 0) {

          flock(fdbLectura, LOCK_UN);
          continue;
        }

        printf("b-inout: %s\n", buff);

        close(fdbEscritura);
        close(fdbLectura);
        break;
      }

    } else {

      int statusHijo1, statusHijo2;
      wait(&statusHijo1);
      printf("Estado de terminacion del hijo 1: %d\n", statusHijo1);
      wait(&statusHijo2);
      printf("Estado de terminacion del hijo 2: %d\n", statusHijo2);
    }
  }
  return 0;
}
