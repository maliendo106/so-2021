#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    int pid;
    pid = fork();

    if (pid == 0)
    {
        // ---> hijo <---
        printf("proceso hijo, llamada getpid: %d\n", getpid());
        printf("proceso hijo, llamada getppid, pid del proceso padre : %d\n", getppid());
    }
    else
    {
        // ---> padre <---
        printf("proceso padre, llamada getpid: %d\n", getpid());
        printf("proceso padre, llamada getppid pid del proceso padre del padre: %d\n\n", getppid()); 
        sleep(1);
    }

    return 0;
}