#include "shell.h"
/**
 * main - function to create a child process
 * Return: 0
 */
char **get_input(void);

int main(void)
{
	while (1)
	{
		char **args = get_input();

		if (args == NULL)
		{
			perror("there no arguments located");
			continue;
		}

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("process creation failed");
			exit(1);
		}
		else
		{
			int stat;

			waitpid(pid, &stat, 0);
			if (WIFEXITED(stat))
			{
				printf("child exited with status of %d\n", WEXITSTATUS(stat));
			}
			else if (WIFSIGNALED(stat))
			{
			printf("child terminated by signal %d\n", WTERMSIG(stat));
			}
		for (int i = 0; args[i] != NULL; i++)
		{
		free(args[i]);
		}
	free(args);
	}
}
return (0);
