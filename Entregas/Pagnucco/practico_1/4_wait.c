#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0) {
    /* hijo */

    printf("Soy el hijo\n");

    for (int i = 10; i != 0; --i) {
      printf(".");
      fflush(stdout);
      sleep(1);
    }
    printf("\n");

  } else {
    /* padre */

    printf("Soy el padre\n");
    fflush(stdout);

    int status;

    // Wait espera a que el proceso hijo termine, y status valdra el status con
    // el que se cerro el proceso hijo
    wait(&status);

    printf("Desde el padre! El hijo termino ");

    // WIFEXITED devuelve true si el proceso hijo termino normalmente
    if (WIFEXITED(status))
      printf("NORMALMENTE");
    else
      printf("ANORMALMENTE");

    // WIFSIGNALED devuelve true si el proceso hijo fue terminado por una señal
    if (WIFSIGNALED(status))
      printf(" mediante la señal %d", WTERMSIG(status));

    // WEXITSTATUS devuelve el status de salida
    printf(" con status %d\n", WEXITSTATUS(status));
    fflush(stdout);
  }
  return 0;
}