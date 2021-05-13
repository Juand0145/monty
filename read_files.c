#include "monty.h"

char *read_files(char *file_name)
{
  int file_descriptor, letters;
	char buffer[BUFSIZ];
  char *arguments_storage;

  file_descriptor = open(file_name, O_RDONLY);

  if (file_descriptor == -1)
	{
		write(2, "Error: Can't open file ", 23);
    write(2, file_name, _strlen(file_name));
	} 

  read(file_descriptor, buffer, BUFSIZ);
  
  letters = _strlen(buffer);

  arguments_storage = malloc(sizeof(char) * letters);

  strcpy(arguments_storage, buffer);

  return (arguments_storage);
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