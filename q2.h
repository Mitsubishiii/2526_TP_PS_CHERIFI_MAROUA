#ifndef Q2_H
#define Q2_H

#define COMMAND_MAXSIZE 1024
#define NULL_CHAR '\0'
#define EXIT_FAILURE 1

void read_user_input(char *command);
void execute_command(char *command, int *status);

#endif // Q2_H

