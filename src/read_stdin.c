/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** read_stdin - 2022
**
** *****************************************************************************
*/

#include	"bsh.h"

char		*std_read_stdin(void)
{
  char          save;
  char          *str;
  int           i;

  i = 0;
  save = '\0';
  str = NULL;
  while (save != '\n')
    {
      read(STDIN_FILENO, &save, 1 * sizeof(char));
      if (save == '\0')
	return (NULL);
      str = std_realloc(str, (i + 2) * sizeof(char));
      str[i] = (save == '\n') ? '\0' : save;
      i = i + 1;
    }
  return (str);
}

