#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Prototipo de las funciones
void Killmanager(int);
void sigmanager(int);

//variable global
int pid;

//main
int main()
{

    pid = fork();

    if (pid == 0)
    {
        signal(SIGINT, sigmanager);
        signal(SIGTSTP, sigmanager);
    }

    else
    {
        signal(SIGINT, Killmanager);
        signal(SIGTSTP, Killmanager);
    }
    while (1)
    {
        printf(".\n");
        sleep(1);
        fflush(stdout);
    }

    return 0;
}

void Killmanager(int SIGNAL)
{
    int status;

    if (SIGNAL == SIGINT)
    {
        printf("El proceso padre capturo la senal 'Interrumpir' y se interrumpe hijo\n");
        fflush(stdout);
        kill(pid, SIGNAL);
    }
    else if (SIGNAL == SIGTSTP)
    {
        printf("El proceso padre capturo la senal 'Suspender' y se suspende al Hijo\n");
        fflush(stdout);
        kill(pid, SIGNAL);
        wait(&status);
        exit(0);
    }
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