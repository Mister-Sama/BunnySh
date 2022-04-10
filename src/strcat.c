/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcat - 2022
**
** *****************************************************************************
*/

#include	"bsh.h"

char		*std_strcat(char	*dest,
			    const char	*src)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  if (src == NULL)
    return (NULL);
  while (dest[j] != '\0')
    j = j + 1;
  while (src[i] != '\0')
    {
      dest[j + i] = src[i];
      i = i + 1;
    }
  dest[j + i] = '\0';
  return (dest);
}
