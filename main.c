#include "monty.h"

int main(int argc, char **argv)
{
  char *commands;
  char **arguments;
  int i, j;
  stack_t *head = NULL;
  //recordar adcionar la carencia de archivo
  if (argc == 1)
  {
    write(2, "USAGE: monty file\n",18);
    exit(EXIT_FAILURE);
  }

  for (i = 1; i < argc; i++)
  {
    commands = read_files(argv[i]);
    arguments = tokenize(commands);

    for (j= 0; arguments[j]; j++)
    {
      if(strcmp(arguments[j], "push") == 0)
        push(&head, atoi(arguments[j + 1]));    

      if (strcmp(arguments[j], "pall") == 0)
        pall(head);

      if (strcmp(arguments[j], "pint") == 0)
        pint(head);

      if (strcmp(arguments[j], "pop") == 0)
        pop(&head);

      if (strcmp(arguments[j], "swap") == 0)
        swap(&head);
    }     
  }

  free_dlistint(head); 
  return (0);
}