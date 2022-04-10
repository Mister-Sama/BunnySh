/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** strcasecmp - 2022
**
** *****************************************************************************
*/

#include	"bsh.h"

bool		std_strcasecmp(const char	*str,
			       const char	*str2)
{
  size_t	i;

  i = 0;
  if (str == NULL && str2 == NULL)
    return (true);
  if (str == NULL || str2 == NULL)
    return (false);
  while (str[i] != '\0' || str2[i] != '\0')
    {
      if ((MIN(str[i])) != (MIN(str2[i])))
	return (false);
      i = i + 1;
    }
  return (true);
}
