#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();
    
    if (pid == 0)
    {
        // ----> hijo <--------
        printf("PROCESO HIJO");
        fflush(stdout);
    }
    else
    {
        //-----> padre <-------
        printf("PROCESO PADRE");
        fflush(stdout);
    }
    return 0;
}
