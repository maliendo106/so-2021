#include <stdio.h>

int main() {
	
    int pid, status;
	
	pid = fork();
	
    if (pid == 0) {
		
        printf("(uso getpid) El id del hijo es %d \n\n" , getpid());
        
        
        printf("(uso getppid) El id es %d que es el id del padre!\n\n" , getppid());
        
		
	} else {
        
        printf("(uso getpid) El id del padre es %d \n\n" , getpid());
       
        wait(&status);

        printf("el proceso hijo termino con status = %d ", status);

   
	}
	return 0;
}
