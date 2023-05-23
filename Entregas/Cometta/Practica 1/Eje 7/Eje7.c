#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>



void sigmanaP(int);
void sigmanaH(int);


int pid; //global

int main() {

    pid = fork();

    if (pid == 0) {

    signal(SIGINT, sigmanaH); 
    signal(SIGTSTP, sigmanaH);
    
    } else {
        
        signal(SIGINT, sigmanaP); 
        signal(SIGTSTP, sigmanaP);

    }

    for (;;){
        printf("...\n\n");
        fflush(stdout);
        sleep(1);

    }
	
    return 0;
    
}

void sigmanaP(int num_s){

int status; 


    if (SIGINT == num_s){
        
        printf("\n\nSe capturo señal 'ctrl + c' o 'interrumpir' y se reenvia al hijo\n\n");
        fflush(stdout);
        kill(pid,num_s);
        

    } else if (SIGTSTP == num_s){

        printf("\n\nSe capturo señal 'ctrl + z' o 'suspender' y se reenvia al hijo...\n\n");
        fflush(stdout);
        kill(pid,num_s);
        wait(&status);
        exit(0);
        
    }
}

void sigmanaH(int num_s){



    if (SIGINT == num_s){
        
        printf("\n\nSeñal 'interrumpir' siendo manejada desde hijo\n\n");
        

    } else if (SIGTSTP == num_s){

        printf("\n\nSeñal 'suspender' siendo manejada desde hijo\n\n");
        exit(0); 
    }



}
