#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int pid;

void sig_handler(int sig_num) {
  if (sig_num == SIGINT) {
    // Se reasigna la señal
    signal(sig_num, sig_handler);

    printf("\nHIJO: Se hizo un Ctrl+C\n");
    fflush(stdout);

    // Frena al hijo de nuevo
    kill(getpid(), SIGSTOP);
  } else if (sig_num == SIGTSTP) {
    printf("\nHIJO: Se hizo un Ctrl+Z. Saliendo!");
    exit(0);
  }
}

void parent_sig_handler(int sig_num) {
  // Se le reasigna la señal
  signal(sig_num, parent_sig_handler);

  printf("\nPADRE: Reenviara signal %d", sig_num);
  fflush(stdout);

  // Le dice al hijo que continue corriendo
  kill(pid, SIGCONT);

  // Reenvia la señal al hijo
  kill(pid, sig_num);

  // Si la señal es de suspender, entonces finalizarse a si mismo
  if (sig_num == SIGTSTP) {
    int status;
    wait(&status);

    printf("\nPADRE: el hijo termino ");

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

    exit(0);
  }
}

int main(void) {

  pid = fork();
  if (pid == 0) {
    /* hijo */

    printf("Soy el hijo, y mi pid es %d\n", getpid());
    fflush(stdout);

    // Se le asigna a la señal SIGINT (Interrupcion) el metodo sig_handler
    signal(SIGINT, sig_handler);

    // Se le asigna a la señal SIGTSTP (Suspender) el metodo sig_handler
    signal(SIGTSTP, sig_handler);

    // Pausa al hijo
    kill(getpid(), SIGSTOP);

    // Se puede hacer este for sin un sleep porque el hijo estara corriendo
    // por tan poco tiempo que no genera un impacto a la cpu o ram.
    for (;;) {
    }

  } else {
    /* padre */

    printf("Soy el padre, y mi pid es %d\n", getpid());
    fflush(stdout);

    // Se asigna a la señal SIGINT (Interrupcion) el metodo parent_sig_handler
    signal(SIGINT, parent_sig_handler);

    // Se asigna a la señal SIGTSTP (Suspender) el metodo parent_sig_handler
    signal(SIGTSTP, parent_sig_handler);

    for (;;) {
      printf(".");
      fflush(stdout);
      sleep(1);
    }
  }
  return 0;
}