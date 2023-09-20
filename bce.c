#include "header.h"

/**
 * change_dir - Changes
 * @cmd: Parsed command
 * @st: Status of last command
 * Return: 0 on success 1
 */
int change_dir(char **cmd, int st)
{
	int value;
	char cwd[PATH_MAX];
	(void)st;

	value = -1;
	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - Display enviroment variable
 * @cmd: parsed command
 * @st: status of last command executed
 * Return: Always 0
 */
int dis_env(char **cmd, int st)
{
	size_t i;
	int len;
	(void)cmd;
	(void)st;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_bul - execute echo cases
 * @st: statue of last command executed
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}

/**
 * history_dis - display history
 * @c: parsed
 * @st: status of last command
 * Return: 0 r -1
 */
int history_dis(char **c, int st)
{
	char *F_N;
	FILE *F_P;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;
	(void)c;
	(void)st;

	F_N = ".shellhistory";
	F_P = fopen(F_N, "r");
	if (F_P == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, F_P)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(F_P);
	return (0);
}
