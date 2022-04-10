/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_text - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

bool            std_read_text(const char	*str,
                              size_t		*index,
                              const char        *token)
{
  size_t	i;

  i = 0;
  if (str == NULL || token == NULL)
    return (false);
  while ((MIN(str[*index + i])) == (MIN(token[i])) && token[i] != '\0')
    i = i + 1;
  *index = (token[i] == '\0') ? *index + i : *index; 
  return (token[i] == '\0');
}
