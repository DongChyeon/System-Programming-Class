/* mysh.c : my shell program, by donghyeon, kimdonghyun90766@gmail.com */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#define MAX_ARG 10
#define MAX_LENGTH 256

void runShell();
int tokenize(char *instr, char *tokens[]);
bool execute(char* instr);

int main() {
    runShell();

    return 0;
}

void runShell() {
    char instruction[MAX_LENGTH];

    while (1) {
        printf("%s $ ", get_current_dir_name());
        fgets(instruction, MAX_LENGTH, stdin);
        instruction[strlen(instruction) - 1] = '\0';
        if (instruction == "\n") continue;
        if (execute(instruction) == false) break;
    }
}

int tokenize(char *instr, char *tokens[]) {
    char* token;
    int i;

    token = strtok(instr, " ");
    if (token == NULL) return 0;
    for (i = 0; i < MAX_ARG && token != NULL; i++) {
        tokens[i] = token;
        token = strtok(NULL, " ");
        if (i == MAX_ARG - 1) {
            tokens[i]= (char*)0;
            break;
        } else if(token == NULL) {
            tokens[i+1] = (char*)0;
            break;
        }
    }
    return i;
}

bool execute(char *instr) {
    char *tokens[MAX_ARG], *token;
    int i, token_end, fd, tempfd;
    pid_t fork_return;
    bool background = false;

    token_end = tokenize(instr, tokens);

    if (token_end == 0 && strcmp(tokens[0], "exit") == 0) {
        return false;
    }

    fork_return = fork();
    if (fork_return == -1){
        printf("fork error\n");
        return false;
    } else if (fork_return == 0) {
        for (i = 0; i < token_end + 1; i++) {
            if (strcmp(tokens[i], "&") == 0) {
                background = true;
                tokens[token_end] = (char*)0;
            } else if (strcmp(tokens[i], ">") == 0) {
                fd = open(tokens[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd < 0) return false;
                dup2(fd, STDOUT_FILENO);
                close(fd);
                tokens[i] = (char*)0;
            } else if (strcmp(tokens[i], ">>") == 0) {
                fd = open(tokens[i + 1], O_WRONLY | O_APPEND, 0644);
                if (fd < 0) return false;
                dup2(fd, STDOUT_FILENO);
                close(fd);
                tokens[i] = (char*)0;
            }
        }
        execvp(tokens[0], tokens);
    } else {
        if (!background) wait();
    }

    return true;
}
