/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strlen - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

size_t          std_strlen(const char	*str)
{
  size_t        i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

