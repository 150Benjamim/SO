#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


void identificarProcesso(){

    printf ("pid: %d\n", getpid());
    printf ("pid pai: %d\n\n", getppid());
}

void criaFilho(){

    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        printf("filho - pid: %d\n", getpid());
        printf("filho - pid pai: %d\n", getppid());
        _exit(0);
    }
    else {
        pid_t terminated_pid = wait(&status);
        printf("\nterminated pid filho: %d -- %d\n", WEXITSTATUS(status), terminated_pid);
        printf("pai - pid: %d\n", getpid());
        printf("pai - pid pai: %d\n", getppid());
    }
}

void dezFilhos(){

    for (int i = 0; i<10; i++){
        pid_t pid;
        int status;

        if ((pid = fork()) == 0) {
            printf("filho - pid: %d\n", getpid());
            printf("filho - pid pai: %d\n", getppid());
            _exit(i+1);
        }
        else {
            pid_t terminated_pid = wait(&status);
            printf("terminated pid: %d\n\n", WEXITSTATUS(status));
        }
    }
}

void dezFilhosConcorrencia(){

    pid_t pid, pid_filho;
    int status;

    for (int i = 0; i<10; i++){
        if((pid = fork()) == 0){
            printf("filho - pid: %d\n", getpid());
            printf("filho - pid pai: %d\n", getppid());
            _exit(i+1);
        }
    }

    while((pid_filho = wait(&status)) > 0){
        if (WIFEXITED(status)) printf("O pid número %d tem valor: %d\n", WEXITSTATUS(status), pid_filho);
        else printf("erro\n");
    }
}


int main (){

    dezFilhosConcorrencia();

    return 0;
}