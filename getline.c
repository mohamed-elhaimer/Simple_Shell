#include "header.h"

/**
 * _getline - read input from
 * Return: the input on a bff
 */
char *_getline()
{
	int i, rd, bfs = BUFSIZE;
	char c = 0, *bf, *buf;

	bf = malloc(bfs);
	if (bf == NULL)
	{
		free(bf);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(bf);
			exit(EXIT_SUCCESS);
		}
		bf[i] = c;
		if (bf[0] == '\n')
			return (enter(bf));
		if (i >= bfs)
		{
			bf = realloc(bf, (bfs + 2));
			if (bf == NULL)
			{
				free(bf);
				return (NULL);
			}
		}
	}
	bf[i] = '\0';
	buf = space(bf);
	free(bf);
	hashtag_handler(buf);
	return (buf);
}


/**
 * enter - Handles newline
 * @string: String to be
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - Modifies the input
 * @str: Input to be modifies
 * Return: Returns the modified
 */
char *space(char *str)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}



/**
 * hashtag_handler - function
 * @buff: input bff
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
	{
		if (buff[j] == '#' && buff[j - 1] == ' ' && buff[j + 1] == ' ')
		{
			buff[j] = '\0';
		}
	}
}
