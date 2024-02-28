#ifndef SHELL_H
#define SHELL_H
#define MAX_BUF_SIZE 1024
#define MAX_COMMAND_LENGTH 100
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *get_input();

#endif
