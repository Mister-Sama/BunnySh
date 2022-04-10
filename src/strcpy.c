/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strspy - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

char		*std_strcpy(char	*dest,
			    const char	*src)
{
  size_t	i;

  i = 0;
  if (src == NULL)
    return (0);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

