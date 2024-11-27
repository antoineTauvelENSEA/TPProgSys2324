#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#include "constantHeader.h"

int main() {
    char console_buffer[BUFFER_SIZE];
    int son_exec_status;
    write(STDOUT_FILENO,WELCOME_MSG,strlen(WELCOME_MSG));
    while(1){
        write(STDOUT_FILENO,PROMPT,strlen(PROMPT));
        read(STDIN_FILENO,console_buffer,BUFFER_SIZE);

        if(fork()==0){
            execlp("fortune","fortune",NULL);
        }
        else{
            wait(&son_exec_status);
        }
    }

    return 0;
}
