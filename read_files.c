#include "monty.h"

void read_files(char *file_name)
{
  stack_t *head = NULL;
  FILE *pfile;
  int i;
  char *line;
  size_t len = 0;
  char **command;
  //char buffer[BUFSIZ];
  //char *arguments_storage;

  //file_descriptor = open(file_name, O_RDONLY);
  pfile = fopen(file_name,"r");

  if (!pfile)
    {
      dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
      exit(EXIT_FAILURE);
    } 
  
  
  while (getline(&line, &len, pfile) != -1)
    {
      command = tokenize(line);
      for (i = 0; command[i]; i++)
	{
	  if(strcmp(command[i], "push") == 0)
	    push(&head, atoi(command[i + 1]));    

	  if (strcmp(command[i], "pall") == 0)
	    pall(head);

	  if (strcmp(command[i], "pint") == 0)
	    pint(head);

	  if (strcmp(command[i], "pop") == 0)
	    pop(&head);

	  if (strcmp(command[i], "swap") == 0)
	    swap(&head);
	}
      free(command);
      count_line++;
    }
  fclose(pfile);
  free(line);
  free_list(head);

  /**
  fd_store = read(file_descriptor, buffer, BUFSIZ);
  
  letters = _strlen(buffer);

  arguments_storage = malloc(sizeof(char) * letters);

  strcpy(arguments_storage, buffer);
  **/
}


int _strlen(char *s)
{
  int i = 0;
  if (s == NULL)
    return 0;
  
  while(*(s+i)!= '\0')
    i++;
  return (i);
}
