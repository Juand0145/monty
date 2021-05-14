#ifndef MONTY_H
#define MONTY_H


/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


/*structures*/



extern unsigned int count_line;
/**
* struct data_s - doubly linked list representation of a stack (or queue)
* @commands: double pointer
* @count_line: unsigned int
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/

typedef struct data_s
{
	char **commands;
	unsigned int count_line;
} data_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*extern variables*/
extern data_t data;

/*opcodes*/
void push(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void add(stack_t **head, unsigned int count_line);
void swap(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int count_line);

/*prototypes*/
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
void _pop(stack_t **head);
void _swap(stack_t **head);
int _nop(void);
void free_list(stack_t *head);
int _strcmp(char *s, char *s2);
void (*get_function(char **command))(stack_t **, unsigned int);
void read_files(char *file_name);
int _strlen(char *s);
char **tokenize(char *arguments);
char **lines(char *line);
char *_strdup(char *line);
int _atoi_verify(char *command);
#endif
