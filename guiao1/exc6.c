#include "exc6.h"


#define MAX_BUF 1024*1024




int adicionar (char *nome, int idade){

    int file_destino = open (FILENAME, O_CREAT | O_WRONLY, 0600);

    Pessoa nova;
    strcpy(nova.nome,nome);
    nova.idade = idade;

    lseek(file_destino,0,SEEK_END);
    write(file_destino,&nova, sizeof(Pessoa));

    int seek = lseek(file_destino,0,SEEK_END);

    close(file_destino);


    return (seek / sizeof (Pessoa));
}


void atualizarIdadeNome (char *nome, int idade){

    int file_destino = open(FILENAME, O_RDWR, 0600);
    Pessoa aux;

    while (read(file_destino,&aux,sizeof (Pessoa)) > 0){

        if (strcmp(aux.nome,nome) == 0){
            aux.idade = idade;
            lseek(file_destino,-sizeof (Pessoa),SEEK_CUR);
            write (file_destino,&aux,sizeof (Pessoa));
            break;
        }
    }

    close (file_destino);

}


void atualizarIdadeRegisto (long registo, int idade){

    int file_destino = open(FILENAME, O_RDWR, 0600);
    Pessoa aux;

    lseek(file_destino,(registo-1)*sizeof (Pessoa),SEEK_SET);
    read(file_destino,&aux,sizeof (Pessoa));
    lseek(file_destino,-sizeof (Pessoa), SEEK_CUR);

    aux.idade = idade;
    write (file_destino,&aux,sizeof (Pessoa));

    close (file_destino);

}


void printPessoa (char *nome){

    int file_destino = open(FILENAME, O_RDONLY, 0600);
    Pessoa aux;

    while (read(file_destino,&aux,sizeof (Pessoa)) > 0){

        if (strcmp(aux.nome,nome) == 0){
            printf("Nome:%s Idade:%d \n", aux.nome, aux.idade);
        }

    }

    close(file_destino);
}


void printListaPessoas (){

    int file_destino = open(FILENAME, O_RDONLY, 0600);
    Pessoa aux;

    while (read(file_destino,&aux,sizeof (Pessoa)) > 0){
        printf("Nome:%s Idade:%d \n", aux.nome, aux.idade);
    }

    close(file_destino);
}