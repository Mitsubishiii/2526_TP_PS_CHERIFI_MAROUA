#ifndef Q1_H
#define Q1_H

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define WELCOME_TEXT "Bienvenue dans le Shell ENSEA.\n"
#define EXIT_TEXT "Pour quitter, tapez 'exit'.\n"
#define SHELL_PROMPT "enseash % "

void display_welcome();
void display_prompt();

#endif // Q1_H

