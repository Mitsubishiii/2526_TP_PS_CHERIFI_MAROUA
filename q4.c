#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

void display_status(int status) {

    char buffer[BUFFER_MAXSIZE];
    int buffer_len = 0;   
    
    if (status < 0) {
        // First loop: just show simple prompt
        write(STDOUT_FILENO, SHELL_PROMPT, strlen(SHELL_PROMPT));
    } 
    else if (WIFEXITED(status)) {
        // Previous command exited normally
        buffer_len = snprintf(buffer, sizeof(buffer), MSG_EXIT, WEXITSTATUS(status));
        write(STDOUT_FILENO, buffer, buffer_len);
    } 
    else if (WIFSIGNALED(status)) {
        // Previous command terminated by a signal
        buffer_len = snprintf(buffer, sizeof(buffer), MSG_SIGN, WTERMSIG(status));
        write(STDOUT_FILENO, buffer, buffer_len);
    }
}