#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include "q5.h"
#include "q6.h"

void find_arguments(char *command, char **args) {
    int i = 0;
    
    // Fill the args array using strsep in the condition 
    while ((args[i] = strsep(&command, " ")) != NULL && i < ARGS_MAXSIZE - 1) {
       
        // Only move to next index if the word isn't empty
        if (*args[i] != NULL_CHAR) { 
            i++;  
        }
    }
    
    // End the array
    args[i] = NULL; 
    
}

void execute_complex_command(char **args, int *status) {

    // Create a new process
    pid_t pid = fork();

    // Child process: execute the command
    if (pid == 0) {  
        
        // Replace the child process with the requested program
        execvp(args[0], args);

        // In case of error print : enseash: No such file or directory
        perror("enseash"); 

        // If execlp fails, terminate child to avoid running parent code
        exit(1);

    }
    else {
        wait(status);
    }
}