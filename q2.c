#include "q1.h"
#include "q2.h"

void read_user_input(char *command) {

    // Read input 
    ssize_t bytes_read = read(STDIN_FILENO, command, COMMAND_MAXSIZE);

    // If nothing was read or an error occurred
    if (bytes_read <= 0) {

         // Terminate string
        command[0] = NULL_CHAR;

        return;
    }

    // Replace the newline character at the end with '\0' (NULL_CHAR)
    command[bytes_read - 1] = NULL_CHAR;
    
}

void execute_command(char *command, int *status) {

    // Create a new process
    pid_t pid = fork();

    // Child process: execute the command
    if (pid == 0) {  

        // Execute the command 
        execlp(command, command, NULL);

        // Print an error message if execvp fails
        perror("enseash"); 

        // If execlp fails, terminate child to avoid running parent code
        exit(EXIT_FAILURE);

    }

    else {  

        // Parent process: wait for the child to finish         
        wait(status);

    }
}
