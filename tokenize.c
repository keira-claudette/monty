#include "monte.h"

/**
 * tokenizer - splits line to strings
 * @lines: pointer to sentence
 * Return: pointer to an array of tokens
 */

char **tokenizer(char *lines)
{
	int j = 0;
	char *token;
	char **tokens = malloc(sizeof(char) * 1024);

	if (!tokens)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
/* get first token*/
	token = strtok(lines, " ");
	while(!token)
	{
		tokens[j] = token;
		j++;
		token = strtok(NULL, " ");
	}

	tokens[j] = NULL;
	return (tokens);
}

char *get_op(char **tokens)
{
	opcode *char;
	int op_index = 0;
/* since strtok converts delimeter to a null byte, traverses the tokens and stop
 * when an char that's not a null byte of encountered
 */
	while (tokens[op_index] == '\0')
	{
		op_index++;
	}
	opcode = tokens[op_index];
	return (opcode);
}

int *op_arg(char **tokens)
{
	char *opcode = get_op(char **tokens);
	int i = 0;

	while (tokens[i] != opcode)
		i++;

	j = i + 1;

	while (tokens[j] == '\0')
		j++;

	op_argument = atoi(tokens[j]);

	return (op_argument);
}