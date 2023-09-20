#include "header.h"

/**
 * check_builtin - Checks if parsed
 * @CM: Parsed command to be
 * Return: 0 or -1
 */
int check_builtin(char **CM)
{
	builtin function[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*CM == NULL)
	{
		return (-1);
	}
	while ((function + i)->command)
	{
		if (_strcmp(CM[0], (function + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - Handles
 * @CM: Array of parsed
 * @st: Status
 * Return: -1 or 0
 */
int handle_builtin(char **CM, int st)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(CM[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(CM, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bul - Exit
 * @CM: Array of
 * @input: Input
 * @argv: Arguments
 * @c: Shell
 * @ST: Exit status
 */
void exit_bul(char **CM, char *input, char **argv, int c, int ST)
{
	int status, i = 0;

	if (CM[1] == NULL)
	{
		free(input);
		free(CM);
		exit(ST);
	}
	while (CM[1][i])
	{
		if (_isalpha(CM[1][i++]) != 0)
		{
			_prerror(argv, c, CM);
			free(input);
			free(CM);
			exit(2);
		}
		else
		{
			status = _atoi(CM[1]);
			if (status == 2)
			{
				_prerror(argv, c, CM);
				free(input);
				free(CM);
				exit(status);
			}
			free(input);
			free(CM);
			exit(status);

		}
	}
}
