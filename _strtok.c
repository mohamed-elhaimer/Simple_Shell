#include "header.h"

/**
 * check_delim - function that
 * @ch: character to check
 * @strr: string of
 * Return: 1 on success, 0 on
 */
unsigned int check_delim(char ch, const char *strr)
{
	unsigned int i;

	for (i = 0; strr[i] != '\0'; i++)
	{
		if (ch == strr[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @strr: string
 * @del: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *strr, const char *del)
{
	static char *tokens;
	static char *N_T;
	unsigned int i;

	if (strr != NULL)
		N_T = strr;
	tokens = N_T;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (check_delim(tokens[i], del) == 0)
			break;
	}
	if (N_T[i] == '\0' || N_T[i] == '#')
	{
		N_T = NULL;
		return (NULL);
	}
	tokens = N_T + i;
	N_T = tokens;
	for (i = 0; N_T[i] != '\0'; i++)
	{
		if (check_delim(N_T[i], del) == 1)
			break;
	}
	if (N_T[i] == '\0')
		N_T = NULL;
	else
	{
		N_T[i] = '\0';
		N_T = N_T + i + 1;
		if (*N_T == '\0')
			N_T = NULL;
	}
	return (tokens);
}
