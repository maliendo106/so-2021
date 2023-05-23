#include <stdio.h>

int main(){
    int pid;
    int status;

    pid=fork();
    if(pid == 0){
        printf("soy el proceso hijo\n");
        fflush(stdout);
    } else {
        printf("soy el proceso padre\n");
        fflush(stdout);
	sleep(1);
    }
    return 0;
}
