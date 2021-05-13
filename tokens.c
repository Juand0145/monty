#include "monty.h"

char **tokenize(char *arguments)
{
  char *line;
  char **commands = malloc(sizeof(char *) *_strlen(arguments));
  int i=0;

  line = strtok(arguments, " \t\r\n");
  while(line != NULL)
    {
      commands[i] = line;
      i++;
      //line_tmp = _strdup(line);
      //commands = lines(line_tmp);
      line = strtok(NULL, " \t\n");
    }
  commands[i] = NULL;

  return commands;
}
