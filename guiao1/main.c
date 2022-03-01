#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_BUF 1024*1024

/*
int main (int argc, char* argv[]){

    //Comandos que dá-mos para o programa executar
    printf("argv[0]: %s\n", argv[0]);
    printf("argv[1]: %s\n", argv[1]);
    printf("argv[2]: %s\n", argv[2]);

    char *buffer = malloc(sizeof(char) * MAX_BUF);

    int file_origem, file_destino;

    if ((file_origem = open(argv[1], O_RDONLY)) == -1){
        perror ("Erro no open origem:");
        return -1;
    }

    if ((file_destino = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1){
        perror ("Erro no open destino:");
        return -1;
    }

    ssize_t bytes_read = 0;

    while ((bytes_read = read(file_origem, buffer, MAX_BUF)) > 0){
        write(file_destino, buffer, bytes_read);
    }

    //Close file descriptors
    close(file_origem);
    close(file_destino);

    //Free buffer
    free(buffer);

    return 0;
}

*/
/*
int main (int argc, char* argv[]){

    char *buffer = malloc(sizeof(char) * MAX_BUF);

    ssize_t bytes_read = 0;

    while ((bytes_read = read(0, buffer, MAX_BUF)) > 0){
        write(1, buffer, bytes_read);
    }

    free(buffer);
}
*/

ssize_t readln(int fd, char *line, size_t size){

    ssize_t read_bytes = 0,
            i = 0; //total_read_bytes

    while ( (read_bytes = read(fd, &line[i], 1)) > 0 && i < size){

        if (line[i] == '\n'){
            i += read_bytes;
            return i;
        }

        i += read_bytes;
    }
    return i;
}


void my_nl (int fd, ssize_t size){

    int i = 1;
    ssize_t read_bytes = 0;
    char *buffer = malloc(sizeof(char) * size);

    while ( (read_bytes = readln(0,buffer,size)) > 0){
        if (buffer[0] == '\n') printf("%s", buffer);
        else printf("\t%d %s", i++, buffer);
    }
}




int main(int argc, char* argv[]){

    ssize_t m;
    char *lista = malloc(sizeof (char) * MAX_BUF);

    my_nl(0, MAX_BUF);

}












