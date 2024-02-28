#include "shell.h"
/**
 * main - simple shell
 * Description: i hope it works
 * Return: 0
 */
int main(void)
{
	char command[100];
	pid_t pid;
	int stat;

	while (1)
	{
		printf("$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			exit(0);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("process failed");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[] = {command, NULL};

			execve(command, args, environ);
			perror(command);
			exit(1);
		}
		else
		{
			waitpid(pid, &stat, 0);
		}
	}
	printf("\n");
	return (0);
}
