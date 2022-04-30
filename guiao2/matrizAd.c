#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define L 10
#define C 100000
#define FILENAME "matriz"








int main(int argc, char* argv[]){

    int fd = open(FILENAME,O_CREAT | O_RDWR, 0600);

    srand(time(NULL));
    int r = rand();
    int matriz[L][C];
    int linha, coluna;

    for (linha = 0; linha<L; linha++){
        for (coluna = 0; coluna<C; coluna++){
            read(rand() % 1000001,&matriz[linha][coluna],sizeof )
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