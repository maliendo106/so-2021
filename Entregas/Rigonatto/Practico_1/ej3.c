/*
3. Escriba un programa similar al anterior, de modo que cada proceso 
obtenga su propio numero de proceso y el de su padre; a continuación 
imprima el resultado. Estudie y utilice las llamadas getpid() y getppid()
*/

#include <stdio.h>

int main(){
    int pid = fork();
    if(pid == 0){//Hijo
        printf("PID del proceso hijo desde el proceso hijo -> %d\n", getpid());
        printf("PID del proceso padre desde el proceso hijo -> %d\n", getppid());
        fflush(stdout);
        
    }else{ //Padre
        printf("PID del proceso padre desde el proceso padre -> %d\n\n",getpid());
        fflush(stdout);
        sleep(1);
    }
    return 0;
}