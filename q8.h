#ifndef QUESTION8_H
#define QUESTION8_H

#define PIPE  3  // |
#define WAIT_CHILD 0

int find_redirection_and_pipe(char **args, int *position);
void execute_complex_command_pipe(char **args, int *status, int position);

#endif //QUESTION8_H