#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    
    if(argc == 1){
        printf("Debe pasar mas argumentos...\n\n");
    }
     else {
    
            for (int i=1; i<argc; i++){
                printf("--> %s \n\n ", argv[i]);
            }  
        } 

    
    return 0;
    
}

