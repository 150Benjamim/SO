#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

#define L 10
#define C 100000

int finder(int matriz[L][C], int key){

    int linha, coluna;
    pid_t pid, pid_terminado;
    pid_t waiter[L];
    int status;
    int r = 0;


    for (linha = 0; linha<L; linha++){
        if ((pid = fork()) == 0){
            for (coluna = 0; coluna<C; coluna++)
                if (matriz[linha][coluna] == key) {
                    _exit(linha);
                }
            _exit(-1);
        }
        else waiter[linha] = pid;
    }


    for (int i = 0; i<L; i++){
        pid_terminado = waitpid(waiter[i],&status,0);
        if (WEXITSTATUS(status) < 10){
            printf("Número encontrado na linha %d\n", WEXITSTATUS(status));
            r = 1;
        }
    }

    return r;
}



int main(int argc, char* argv[]){

    srand(time(NULL));
    int r = rand();
    int matriz[L][C];
    int linha, coluna;

    for (linha = 0; linha<L; linha++){
        for (coluna = 0; coluna<C; coluna++){
            matriz[linha][coluna] = rand() % 1000001;
        }
    }

    int key;

    matriz[3][31232] = 34;
    matriz[4][31232] = 34;
    matriz[5][31232] = 34;

    if (argc<2) key = rand() % 1000001;
    else key = atoi(argv[1]);

    int existeInt = finder(matriz,key);

    if (existeInt) printf("Existe o número %d na matriz\n", key);
    else printf("Não existe o número %d na matriz\n", key);
}