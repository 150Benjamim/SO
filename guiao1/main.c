#include "excs.h"
#include "exc6.h"
#include "time.h"

int main(int argc, char* argv[]){

    double time_spent = 0.0;
    clock_t begin = clock();

    if (strcmp(argv[1], "-i") == 0)
    {
        int reg = adicionar(argv[2], atoi(argv[3]));
        printf("registo %d\n", reg);
    }
    else if (strcmp(argv[1], "-u") == 0)
    {
        atualizarIdadeNome(argv[2], atoi(argv[3]));
    }
    else if (strcmp(argv[1], "-o") == 0)
    {
        atualizarIdadeRegisto(atol(argv[2]), atoi(argv[3]));
    }
    else if (strcmp(argv[1], "-l") == 0)
    {
        printPessoa(argv[2]);
    }
    else if (strcmp(argv[1], "-la") == 0)
    {
        printListaPessoas();
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução:%f segundos\n", time_spent);

    return 0;
}












