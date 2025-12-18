#ifndef QUESTION7_H
#define QUESTION7_H

#include <fcntl.h>


#define REDIR_NONE 0
#define REDIR_IN   1  // <
#define REDIR_OUT  2  // >
#define PIPE  3  // |
#define WRITE_OWNER_PERMISSION 0644 //owner can write

int find_redirection(char **args, int *position);
void apply_redirection(char **args, int position, int type);
void execute_complex_command_redir(char **args, int *status, int position, int type);

#endif //QUESTION7_H