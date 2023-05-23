#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>



void sigmana(int);

int main() {

    signal(SIGINT, sigmana); 
    signal(SIGTSTP, sigmana);

    for (;;){
        printf("...\n\n");
        fflush(stdout);
        sleep(1);

    }
	
    return 0;
    
}

void sigmana(int num_s){

    signal(SIGINT, sigmana);
    signal(SIGTSTP, sigmana);

    if (SIGINT == num_s){
        printf("\n\nSe capturo señal 'ctrl + c' o 'interrumpir'");    
    } else if (SIGTSTP == num_s){
        printf("\n\nSe capturo señal 'ctrl + z' o 'suspender'");
        exit(0);
    }

}
