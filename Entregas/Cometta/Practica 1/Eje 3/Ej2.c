#include <stdio.h>

int main() {
	
    int pid;
	
	pid = fork();
	
    if (pid == 0) {
		
        printf("(uso getpid) El id del hijo es %d \n\n" , getpid());
        
        printf("(uso getppid) El id es %d que es el id del padre!\n\n" , getppid());
		
	} else {
        
        printf("(uso getpid) El id del padre es %d \n\n" , getpid());
       
        printf("(uso getppid) El id del padre es %d \n\n" , getppid());
		
	}
	return 0;
}
