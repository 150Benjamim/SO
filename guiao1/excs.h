#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


#ifndef GUIAO1_EXCS_H
#define GUIAO1_EXCS_H

#define MAX_BUF 1024*1024


int my_cp (int argc, char* argv[]);
int my_cat (int argc, char* argv[]);
ssize_t readln (int fd, char *line, size_t size);
void my_nl (int fd, ssize_t size);



#endif //GUIAO1_EXCS_H