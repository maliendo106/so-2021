#include <stdio.h>

int main(){
    int pid;
    int status;

    pid=fork();
    if(pid == 0){
        printf("soy el proceso hijo, mi pid: %d\n\n",getpid());
        printf("soy el proceso hijo, el pid de mi padre: %d\n\n",getppid());
        fflush(stdout);
    } else {
        printf("soy el proceso padre, mi pid: %d\n\n", getpid());
        fflush(stdout);
        sleep(1);
    }
    return 0;
}
