#include "q1.h"
#include "q2.h"
#include "q3.h"

int read_and_process_input(char *command) {

    // Read input 
    ssize_t bytes_read = read(STDIN_FILENO, command, COMMAND_MAXSIZE);

    // Replace the newline character at the end with '\0' (NULL_CHAR)
    command[bytes_read - 1] = NULL_CHAR;

    // Case 1: Ctrl+D exit
    if (bytes_read <= 0) {
        write(STDOUT_FILENO, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
        return SHELL_EXIT;
    }

    // Case 2: User typed "exit"
    if (strcmp(command, EXIT_COMMAND) == 0) {
        write(STDOUT_FILENO, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
        return SHELL_EXIT;
    }

    // Case 3: Empty command (Enter)
    if (command[0] == NULL_CHAR) {
        return SHELL_CONTINUE;
    }

    // Case 4: Any other command, continue and execute it
    return SHELL_CONTINUE;
}


