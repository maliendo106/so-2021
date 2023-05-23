#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0) {
    /* hijo */

    printf("Soy el hijo, y mi pid es %d\n", getpid());
    fflush(stdout);

    for (;;) {
      printf(".");
      fflush(stdout);
      sleep(1);
    }

  } else {
    /* padre */

    printf("Soy el padre, y mi pid es %d\n", getpid());
    fflush(stdout);

    int status;
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

// La pagina man 7 signals presenta la siguiente tabla mostrando todas las
// señales posibles

// Signal      Standard   Action   Comment
// ────────────────────────────────────────────────────────────────────────
// SIGABRT      P1990      Core    Abort signal from abort(3)
// SIGALRM      P1990      Term    Timer signal from alarm(2)
// SIGBUS       P2001      Core    Bus error (bad memory access)
// SIGCHLD      P1990      Ign     Child stopped or terminated
// SIGCLD         -        Ign     A synonym for SIGCHLD
// SIGCONT      P1990      Cont    Continue if stopped
// SIGEMT         -        Term    Emulator trap
// SIGFPE       P1990      Core    Floating-point exception
// SIGHUP       P1990      Term    Hangup detected on controlling
// terminal
//                                 or death of controlling process
// SIGILL       P1990      Core    Illegal Instruction
// SIGINFO        -                A synonym for SIGPWR
// SIGINT       P1990      Term    Interrupt from keyboard
// SIGIO          -        Term    I/O now possible (4.2BSD)
// SIGIOT         -        Core    IOT trap. A synonym for SIGABRT
// SIGKILL      P1990      Term    Kill signal
// SIGLOST        -        Term    File lock lost (unused)
// SIGPIPE      P1990      Term    Broken pipe: write to pipe with no
//                                 readers; see pipe(7)
// SIGPOLL      P2001      Term    Pollable event (Sys V);
//                                 synonym for SIGIO
// SIGPROF      P2001      Term    Profiling timer expired
// SIGPWR         -        Term    Power failure (System V)
// SIGQUIT      P1990      Core    Quit from keyboard
// SIGSEGV      P1990      Core    Invalid memory reference
// SIGSTKFLT      -        Term    Stack fault on coprocessor (unused)

// SIGSTOP      P1990      Stop    Stop process
// SIGTSTP      P1990      Stop    Stop typed at terminal
// SIGSYS       P2001      Core    Bad system call (SVr4);
//                                 see also seccomp(2)
// SIGTERM      P1990      Term    Termination signal
// SIGTRAP      P2001      Core    Trace/breakpoint trap
// SIGTTIN      P1990      Stop    Terminal input for background process
// SIGTTOU      P1990      Stop    Terminal output for background process
// SIGUNUSED      -        Core    Synonymous with SIGSYS
// SIGURG       P2001      Ign     Urgent condition on socket (4.2BSD)
// SIGUSR1      P1990      Term    User-defined signal 1
// SIGUSR2      P1990      Term    User-defined signal 2
// SIGVTALRM    P2001      Term    Virtual alarm clock (4.2BSD)
// SIGXCPU      P2001      Core    CPU time limit exceeded (4.2BSD);
//                                 see setrlimit(2)
// SIGXFSZ      P2001      Core    File size limit exceeded (4.2BSD);
//                                 see setrlimit(2)
// SIGWINCH       -        Ign     Window resize signal (4.3BSD, Sun)