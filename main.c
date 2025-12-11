#include "q1.h"
#include "q2.h"

int main(void) {

    char command[MAX_COMMAND_SIZE] = {0};
    int status = 0;

    display_welcome();
    display_exit_instruction();

    while(1) {
        display_prompt();
        read_user_input(command);
        execute_command(command, &status);
    }
    return 0;
}