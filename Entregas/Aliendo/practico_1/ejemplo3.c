#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    int pid;
    pid = fork();
    
    if ( pid == 0 ) {
        // hijo
        printf("hijo, llamada getpid: %d\n", getpid() );
        printf("hijo, llamada getppid: %d\n", getppid() );  // pid del proceso padre
    } else {
        // padre
        printf("padre, llamada getpid: %d\n", getpid() );
        printf("padre, llamada getppid: %d\n\n", getppid() );  // pid del proceso padre
        sleep(1);
    }

    return 0;
}