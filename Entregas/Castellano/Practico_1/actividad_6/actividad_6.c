#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int pid;
void sigManager(int);

int main() {
    signal(SIGINT,sigManager);
    signal(SIGTSTP,sigManager);
    while(1){
        printf("esperando...\n");
        sleep(3);
    }
}

void sigManager(int sig_num) {
    if(sig_num==SIGINT) {
        printf("\nsenal de interrupcion\n");
    }
    if(sig_num==SIGTSTP) {
        printf("\nsenal de suspension, terminando proceso\n");
        fflush(stdout);
        exit(0);
    }
}