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

	buffer[strcspn(buffer, "\n")] = '\0';
	char *space_finder = strchr(buffer, ' ');

	if (space_finder != NULL)
		*space_finder = '\0';
	return (buffer);
}
