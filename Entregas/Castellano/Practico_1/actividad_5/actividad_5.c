#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*si matamos al proceso hijo con un kill <pid_hijo>, obtendremos status=15*/

int main(){
    int pid;
    int status;

    pid=fork();
    if(pid == 0){
        printf("soy el proceso hijo, mi pid: %d\n\n",getpid());
        fflush(stdout);
        sleep(15);
    } else {
        printf("soy el proceso padre, mi pid: %d\n\n", getpid());
        fflush(stdout);
        wait(&status);
        if (WIFEXITED(status)) {
		    printf("el proceso hijo termino correctamente, con status: %d\n", WEXITSTATUS(status));
     	} else {
		    printf("el proceso hijo termino incorrectamente, con status: %d\n", WTERMSIG(status));
    	}	
    }
    return 0;
}