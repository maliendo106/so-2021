#include <stdio.h>

int main() {
	
    int pid;

	pid = fork();
	
    if (pid == 0) {
        printf("hijo\n\n");
        fflush(stdout);
	}else {
	    printf("padre\n");
        fflush(stdout);
	}
	return 0;
}