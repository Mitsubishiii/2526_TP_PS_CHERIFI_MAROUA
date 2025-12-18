#ifndef Q4_H
#define Q4_H

#include <sys/wait.h>  

#define BUFFER_MAXSIZE 1024
#define MSG_EXIT "enseash [exit:%d] %% "
#define MSG_SIGN "enseash [sign:%d] %% "

void display_status(int status);

#endif // Q4_H