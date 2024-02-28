#include "shell.h"
/**
 * main - function that creates child
 * Dsignal - ctrl + d
 * Description: it supose to work
 * Return: 0
 */
char **get_input(void);

void handel_signal(int signal)
{
	printf("\nExiting shell....\n");
	exit(0);
}

int main(void)
{
	signal(SIGINT, handel_signal);

	while (1)
	{
		char **args = get_input();

		if (args == NULL)
		{
			perror("there no arguments located");
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
		printf("$ ");
		fflush(stdout);
	}
	return (0);
}
