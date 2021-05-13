#include "monty.h"

void read_files(char *file_name)
{
  stack_t *head = NULL;
  FILE *pfile;
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
	count_line++;
      command = tokenize(line);
	  if(strcmp(command[0], "push") == 0)
	     push(&head, atoi(command[1]));     
	  else if(strcmp(command[0], "pall") == 0)
	    pall(head);
	  else if (strcmp(command[0], "pint") == 0)
	    pint(head);
	  else if (strcmp(command[0], "pop") == 0)
	    pop(&head);
	  else if (strcmp(command[0], "swap") == 0)
	    swap(&head);
	  else
	  {
		  dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", count_line, command[0]);
		  free(command);
		  fclose(pfile);
		  free_list(head);
		  free(line);
		  exit(EXIT_FAILURE);
	  }
      free(command);
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
