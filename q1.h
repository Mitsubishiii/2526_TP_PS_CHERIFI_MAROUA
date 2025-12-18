#ifndef Q1_H
#define Q1_H

// Must be defined before any include: enables POSIX APIs needed for clock_gettime()
#define _POSIX_C_SOURCE 199309L

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define WELCOME_TEXT "Bienvenue dans le Shell ENSEA.\n"
#define EXIT_TEXT "Pour quitter, tapez 'exit'.\n"
#define SHELL_PROMPT "enseash % "

void display_welcome(void);
void display_exit_instruction(void);
void display_prompt(void);


#endif // Q1_H

