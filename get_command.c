#include "shell.h"
/**
 * get_input - function returns first
 *		arg to be excuted
 * Return: the first argument that must be excuted
 */
char **get_input()
{
	char *buffer = malloc(MAX_COMMAND_LENGTH * sizeof(char));

	if (buffer == NULL)
	{
		perror("unsuccessful allocation process");
		return (NULL);
	}

	printf("$ ");
	fgets(buffer, MAX_COMMAND_LENGTH, stdin);
	char **args = malloc(MAX_ARGS * sizeof(char *));

	if (args == NULL)
	{
		perror("unsuccessful allocation process for args");
		free(buffer);
		return (NULL);
	}
	int i = 0;
	char *token = strtok(buffer, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	if (token != NULL)
		fprintf(stderr, "too many arguments\n");
	free(args);
	free(buffer);
	return (args);
}
