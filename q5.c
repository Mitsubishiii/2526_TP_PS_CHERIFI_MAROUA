#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include "q5.h"

struct timespec time_start;
struct timespec time_end;

// Records the start time before command execution
void timer_start() {
    clock_gettime(CLOCK_MONOTONIC, &time_start);
}

// Records the end time after process termination
void timer_end() {
    clock_gettime(CLOCK_MONOTONIC, &time_end);
}

// Calculates elapsed time in milliseconds 
int get_time()
{
    // Calculate seconds and nanoseconds differences separately 
    long sec_diff  = time_end.tv_sec  - time_start.tv_sec;
    long nsec_diff = time_end.tv_nsec - time_start.tv_nsec;

    // Combine results into a single value in milliseconds 
    return (int)(sec_diff * 1000 + nsec_diff / 1000000);
}

// Formats and displays the prompt with exit status/signal and execution time
void display_status_and_time(int status) {

    char buffer[BUFFER_MAXSIZE];
    int buffer_len = 0;  

    // Get program time execution
    int time_execution = get_time(); 
    
    if (status < 0) {
        // First loop: just show simple prompt
        write(STDOUT_FILENO, SHELL_PROMPT, strlen(SHELL_PROMPT));
    } 
    else if (WIFEXITED(status)) {
        // Previous command exited normally
        buffer_len = snprintf(buffer, sizeof(buffer), MSG_EXIT_TIME, WEXITSTATUS(status), time_execution);
        write(STDOUT_FILENO, buffer, buffer_len);
    } 
    else if (WIFSIGNALED(status)) {
        // Previous command terminated by a signal
        buffer_len = snprintf(buffer, sizeof(buffer), MSG_SIGN_TIME, WTERMSIG(status), time_execution);
        write(STDOUT_FILENO, buffer, buffer_len);
    }
}
