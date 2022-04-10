/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** memcpy - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

void		*std_memcpy(void	*dest,
			    const void	*src,
			    size_t	n)
{
  size_t	i;

  i = 0;
  while (i != n)
    {
      ((char *) dest)[i] = ((char *) src)[i];
      i = i + 1;
    }
  return (dest);
}
