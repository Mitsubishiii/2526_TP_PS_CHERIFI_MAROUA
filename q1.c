#include "q1.h"

void display_welcome() {
    // Print the welcome message 
    write(STDOUT_FILENO, WELCOME_TEXT, strlen(WELCOME_TEXT));
}

void display_prompt() {
    // Print the exit instructions
    write(STDOUT_FILENO, EXIT_TEXT, strlen(EXIT_TEXT));
    // Print the shell prompt
    write(STDOUT_FILENO, SHELL_PROMPT, strlen(SHELL_PROMPT));
}


