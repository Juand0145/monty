#include "monty.h"
int count_line = 0;

int main(int argc, char **argv)
{
  
  //recordar adcionar la carencia de archivo
  if (argc != 2)
    {
      write(2, "USAGE: monty file\n",18);
      exit(EXIT_FAILURE);
    }

  read_files(argv[1]);
    
  
  return (EXIT_SUCCESS);
}
