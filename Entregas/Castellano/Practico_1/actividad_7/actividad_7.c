#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int pid;
void sigManagerPadre(int);
void sigManagerHijo(int);

int main() {

    pid=fork();

    if (pid==0){
        signal(SIGINT,sigManagerHijo);
        signal(SIGTSTP,sigManagerHijo);
    } else {
        signal(SIGINT,sigManagerPadre);
        signal(SIGTSTP,sigManagerPadre);
    }

    while(1){
        printf("esperando...\n");
	fflush(stdout);
        sleep(3);
    }
}

void sigManagerPadre(int sig_num) {

    int status;

    if(sig_num==SIGINT) {
        printf("\nel padre capturo una senal de interrupcion\n");
        kill(pid,sig_num);
    }

    if(sig_num==SIGTSTP) {
        printf("\nel padre capturo una senal de suspension\n");
        fflush(stdout);
        kill(pid,sig_num);
        wait(&status);
        exit(0);
    }
}

void sigManagerHijo(int sig_num) {

    if(sig_num==SIGINT) {
        printf("\nel hijo capturo una senal de interrupcion\n");
    }

    if(sig_num==SIGTSTP) {
        printf("\nel hijo capturo una senal de suspension\n");
        fflush(stdout);
        exit(0);
    }
}
