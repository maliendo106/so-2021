#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int pid;
void signalControl(int);

int main(){

    signal(SIGINT,signalControl);  //Ctrl C
    signal(SIGTSTP,signalControl);  //Ctrl Z

    while(1){

        printf(".\n");
        sleep(1);

    }

    return 0;
}

void signalControl(int signal_num){

    if(signal_num == SIGINT){

        printf("Señal x Ctrl C recibida\n");
       
    }else if(signal_num == SIGTSTP){

        exit(0);
        
    }
}