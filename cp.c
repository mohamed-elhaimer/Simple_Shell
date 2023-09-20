#include "header.h"

/**
 * parse_cmd - the command  from stdin
 * @input: String  stdin
 * Return: to be used as arg
 */
char **parse_cmd(char *input)
{
	char **arg;
	char *argu;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arg = malloc(sizeof(char *) * buffsize);
	if (!arg)
	{
		free(arg);
		perror("hsh");
		return (NULL);
	}
	argu = _strtok(input, "\n\t\r\a ");
	for (i = 0; argu; i++)
	{
		arg[i] = argu;
		argu = _strtok(NULL, "\n\t\r\a ");
	}
	arg[i] = NULL;

	return (arg);
}
