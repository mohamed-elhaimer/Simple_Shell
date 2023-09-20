#include "header.h"

/**
 * print_error - error message
 * @input:  recieved from user
 * @counter:  of shell loop
 * @argv:   program starts(argv[0] == Shell Program Name)
 */

void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _prerror - Prints custom Error
 * @argv:   program (argv[0] == Shell Program Name)
 * @c: Error Count
 * @cmd:   parsed command strings
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * error_file -  custom Error
 * @argv:   program starts(argv[0] == Shell Program Name)
 * @c:  Count
 */
void error_file(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
