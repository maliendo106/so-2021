#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int sig_num) {
  // Se le reasigna la señal
  signal(sig_num, sig_handler);

  if (sig_num == SIGINT)
    printf("\nSe hizo un Ctrl+C\n");
  else if (sig_num == SIGTSTP) {
    printf("\nSe hizo un Ctrl+Z\nSaliendo!\n");
    exit(0);
  }
}

int main(void) {
  // Se le asigna a la señal SIGINT (Interrupcion) el metodo sig_handler
  signal(SIGINT, sig_handler);

  // Se le asigna a la señal SIGTSTP (Suspender) el metodo sig_handler
  signal(SIGTSTP, sig_handler);

  for (;;) {
    printf(".");
    fflush(stdout);
    sleep(1);
  }
}