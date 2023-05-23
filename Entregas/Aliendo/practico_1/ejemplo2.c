#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	
    int pid;
	pid = fork();

    if (pid == 0) {
		//Hijo
        printf("proceso hijo\n");
    } else {
		//Padre
        printf("proceso padre\n");
    }

    return 0;
}
