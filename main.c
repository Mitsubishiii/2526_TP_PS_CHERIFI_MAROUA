#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include "q5.h"
#include "q6.h"
#include "q7.h"
#include "q8.h"


int main(void) {

    char command[COMMAND_MAXSIZE] = {0};
    char *args[ARGS_MAXSIZE];

    // Set to -1 so the first prompt is simple (no previous command yet)
    int status = -1;

    // Show initial shell messages
    display_welcome();
    display_exit_instruction();

    while(1) {

        // Show prompt with return code and execution time
        display_status_and_time(status);

        // Read user input and handle errors or empty lines
        int result = read_and_process_input(command);

            // Terminate loop if exit command or CTRL+D is entered
            if (result == SHELL_EXIT) {
                break;
            }

            // Proceed if command is valid
            if (result == SHELL_CONTINUE) {

                // Split command string into individual arguments
                find_arguments(command, args);

                // Identify special operators : <, > or |
                int position = 0;
                int type = find_redirection_and_pipe(args, &position);
                
                // Record start time of the command
                timer_start();

                // Execute based on the detected operator type
                if (type == REDIR_IN || type == REDIR_OUT) {

                    // Handle file redirection
                    execute_complex_command_redir(args, &status, position, type);

                }
                else if(type == PIPE) {

                    // Handle piping
                    execute_complex_command_pipe(args, &status, position);
                    
                }
                else if(type == REDIR_NONE) { 

                    // Execute standard command without operators
                    execute_complex_command(args, &status);

                }

                // Record end time 
                timer_end();
                
            }
        }
    return 0;
}