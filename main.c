#include "monte.h"
#define SIZE 1024

/**
 * main - interprets monty byte code
 * @argc: argument count passed by user from the terminal
 * @argv: array of commands passed by user
 * Return: tbd
 */

int main(unsigned int argc, char **argv)
{
        char *filename = argv[1];
	char **lines;
        FILE *fileptr;
	int readbytes;


        if (argc <= 1)
        {
                if (isatty(STDERR_FILENO)== 1)
                {
                        perror("USAGE: monty file \n");
                        exit(EXIT_FIALURE);
                }
        }
        fileptr = fopen(filename, "r");
        if (!fileptr)
        {
                perror("Error: Can\'t open file <>\n");
                exit(EXIT_FAILURE);
        }
	lines = malloc (SIZE);
	if (!lines)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}
