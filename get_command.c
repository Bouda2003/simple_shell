#include "shell.h"
/**
 * get_input - function returns first
 *		arg to be excuted
 * Return: the first argument that must be excuted
 */
char *get_input()
{
	char *buffer = malloc(MAX_COMMAND_LENGTH * sizeof(char));

	if (buffer == NULL)
	{
		perror("unsuccessful process");
		return (NULL);
	}

	printf("$ ");
	fgets(buffer, MAX_COMMAND_LENGTH, stdin);
	char **args = malloc(MAX_ARGS * sizeof(char *));
	int i = 0;
	char *token = strtok(buffer, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	return (args);
}
