#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include "q5.h"
#include "q6.h"
#include "q7.h"
#include "q8.h"


// Find the redirection and pipe symbol and return its type and position 
int find_redirection_and_pipe(char **args, int *position) {
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], "<") == 0)  { 
            *position = i; 
            return REDIR_IN; 
        }
        if (strcmp(args[i], ">") == 0)  {
            *position = i; 
            return REDIR_OUT;
        }
        if (strcmp(args[i], "|") == 0)  {
            *position = i; 
            return PIPE; 
        }
    }
    return REDIR_NONE;
}

void execute_complex_command_pipe(char **args, int *status, int position) {
    
    // File descriptors for the pipe: fds[0] for reading, fds[1] for writing
    int fds[2]; 
    
    // Create the pipe
    if (pipe(fds) == -1) { 
        perror("pipe"); 
        return; 
    }

    // Map pipe end
    int fd_read  = fds[0]; 
    int fd_write = fds[1]; 

    // Cut original array at "|" and set pointer for second command
    args[position] = NULL;         
    char **args2 = &args[position + 1]; 

    // Create a new proces
    pid_t pid1 = fork();

    // First child: execute left command
    if (pid1 == 0) { 
        // Redirect stdout to pipe write end
        dup2(fd_write, STDOUT_FILENO);

        close(fd_read); 
        close(fd_write); 

        // Execute the command 
        execvp(args[0], args);

        // Print an error message if execvp fails
        perror("enseash"); 

        // If execlp fails, terminate child to avoid running parent code
        exit(EXIT_FAILURE);
    }

    // Create a new proces
    pid_t pid2 = fork();

    // Second child: execute right command
    if (pid2 == 0) { 
        // Redirect stdin to pipe read end
        dup2(fd_read, STDIN_FILENO);

        close(fd_read); 
        close(fd_write); 

        // Execute the command 
        execvp(args2[0], args2);

        // Print an error message if execvp fails
        perror("enseash"); 

        // If execlp fails, terminate child to avoid running parent code
        exit(EXIT_FAILURE);
    }

    // Parent closes pipe ends to prevent blocking
    close(fd_read); 
    close(fd_write);

    // Wait for both children to finish
    waitpid(pid1, status, WAIT_CHILD);
    waitpid(pid2, status, WAIT_CHILD);

}