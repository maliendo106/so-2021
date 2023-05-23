#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigmanager(int);

int main()
{

    signal(SIGINT, sigmanager);  //Se busca la señal en SIGNINT DE -> Ctrl + C
    signal(SIGTSTP, sigmanager); //Se busca la señal en SIGTSTP  DE -> Ctrl + Z

    while (1)
    {
        printf(".\n");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}

void sigmanager(int SIGNAL)
{

    signal(SIGNAL, sigmanager);

    if (SIGNAL == SIGINT)
    {
        printf("Se capturo la senal 'Interrumpir'\n");
        fflush(stdout);
    }
    else if (SIGNAL == SIGTSTP)
    {
        printf("Se capturo la senal 'Suspender' \n Se procedera a terminar el proceso\n");
        fflush(stdout);
        exit(0);
    }
}