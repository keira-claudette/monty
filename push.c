#include "monteh"
/**
 * push - adds an elements to the stack(or queue)
 * @line_number: line to interpret
 * @stack: pointer to stack to add element
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *line = all_lines[line_number - 1];
	char **linechunks = tokenizer(line);
	int i = 0, j, n;
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;
/*
 * parse the line to get int argument by finding first instance of
 * a non null-byte which would be the opcode
 * second instance of non null-byte char will be the int argument
 */
	for (; linechunks[i] != push; i++)
		;
	j = i + 1;
	for (; linechunks[j] == '\0'; j++)
		;
	n = atoi(linechunks[j]);
/*Check for int,atoi returns 0 on failure to convert*/
	if (n == 0)
	{
		perror("L<line_number>: usage: push integer \n");
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		perror("Error: malloc failed \n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!stack)
	{
		*stack = new_node;
	}
	while (temp && temp->next)
	{
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
}
