#include "header.h"

/**
 * read_file - from the argument File
 * @file: commands
 * @argv: passed
 * Return: -1 or 0
 */
void read_file(char *file, char **argv)
{
	FILE *filepointer;
	char *li = NULL;
	size_t len = 0;
	int count = 0;

	filepointer = fopen(file, "r");
	if (filepointer == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&li, &len, filepointer)) != -1)
	{
		count++;
		treat_file(li, count, filepointer, argv);
	}
	if (li)
		free(li);
	fclose(filepointer);
	exit(0);
}

/**
 * treat_file - their execution
 * @li: file
 * @count: Error
 * @filepointer: File
 * @argv:  li arguments
 */
void treat_file(char *li, int count, FILE *filepointer, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = parse_cmd(li);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bul_for_file(cmd, li, filepointer);
	else if (check_builtin(cmd) == 0)
	{
		stat = handle_builtin(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = check_cmd(cmd, li, count, argv);
		free(cmd);
	}
}

/**
 * exit_bul_for_file -   handler for file input
 * @li: li  a file
 * @cmd: Parsed
 * @fd: File Descriptor
 */
void exit_bul_for_file(char **cmd, char *li, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(li);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmd[1]);
	free(li);
	free(cmd);
	fclose(fd);
	exit(status);
}
