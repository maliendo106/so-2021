#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int pid;
int status;
void signalControl(int);
void signalControlSON(int);

int main() {
    
    pid = fork();

    if (pid == 0){

        signal(SIGINT, signalControlSON);  //Ctrl C
        signal(SIGTSTP, signalControlSON); //Ctrl Z

    }else{

        signal(SIGINT, signalControl);  //Ctrl C
        signal(SIGTSTP, signalControl); //Ctrl Z

    }
    
    while (1) {

                printf(".\n");
                sleep(1);

            }
    return 0;
}

void signalControl(int signal_num) {

        kill(pid, signal_num);

        if(signal_num == SIGTSTP){

            wait(&status);
            exit(0);

        }

}

void signalControlSON(int signal_num) {

        if (signal_num == SIGINT) {

            printf("Señal Ctrl C recibida \n");
            
        }else if (signal_num == SIGTSTP){

            exit(0);

        }
    
}