#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#ifndef GUIAO1_EXC6_H
#define GUIAO1_EXC6_H

#define FILENAME "lista de pessoas"


typedef struct Pessoas{

    char nome[200];
    int idade;
} Pessoa;


int adicionar (char *nome, int idade);
void atualizarIdadeNome (char *nome, int idade);
void atualizarIdadeRegisto (long registo, int idade);
void printPessoa (char *nome);
void printListaPessoas ();



#endif //GUIAO1_EXC6_H