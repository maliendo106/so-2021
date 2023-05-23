#include <stdio.h>

int main(){

    int pid;

    pid = fork();

    if (pid == 0){

        printf("Hola soy el hijo\n\n"); 

    } else {

        printf("Hola soy el padre\n");
        sleep(1);
        
    }
    
    return 0;
}