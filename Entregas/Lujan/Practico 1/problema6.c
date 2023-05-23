#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/*
6. Escriba un programa que capture las señales “Ctrl-C” (Interrumpir) 
y “Ctrl-Z” (Suspender), en el primer caso el programa debe escribir un mensaje en pantalla, en el segundo debe terminar.

Utilice el siguiente procedimiento: defina una función que retorne 
void para manejar la señal y asigne una señal a esta función por medio 
de la llamada signal()

void sigmanager(int sig_num) {
	/* Reasignar la señal *’/
	signal(SIGNAL, sigmanager):
	...
	fflush(stdout);
	}
	...
	signal(SIGNAL, sigmanager);
*/
void signal_handler(int signal_num);

int main(void)
{

    signal(SIGINT, signal_handler);
    signal(SIGTSTP, signal_handler);

    for (;;)
    {
        sleep(999);
    }
}

void signal_handler(int signal_num)
{

    if (signal_num == SIGINT)
    {
        printf("\n Se Oprimio Ctrl + C.\n");
    }
    else if (signal_num == SIGTSTP)
    {
        printf("\n Proceso Terminado al Oprimir Ctrl + Z. \n");
        exit(0);
    }
}