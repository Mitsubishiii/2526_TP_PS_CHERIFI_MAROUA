#ifndef Q5_H
#define Q5_H

#include <time.h>

#define MSG_EXIT_TIME "enseash [exit:%d|%dms] %% "
#define MSG_SIGN_TIME "enseash [sign:%d|%dms] %% "

extern struct timespec time_start ;
extern struct timespec time_end ;

void start_timer(void);
void end_timer(void);
int get_time(void);
void display_status_and_time(int status);

#endif // Q5_H