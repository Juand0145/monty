#include "monty.h"

/**
* main - principal function of the monty interpreter
* arcg: number of arguments
* argv: arguments in the shell
*
* Return: 0 in success and 1 in case failure
*/

int count_line = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	read_files(argv[1]);
	return (EXIT_SUCCESS);
}
