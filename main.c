#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

int main(void) {

    char command[COMMAND_MAXSIZE] = {0};
    
    // Set to -1 so the first prompt is simple (no previous command yet)
    int status = -1;

    display_welcome();
    display_exit_instruction();

    while(1) {

        display_status(status);

        int result = read_and_process_input(command);
            if (result == SHELL_EXIT) {
                break;
            }

            if (result == SHELL_CONTINUE) {
                execute_command(command, &status);
            }
        }
    return 0;
}