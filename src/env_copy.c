/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** env_copy - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

char            **std_env_copy(char	**env)
{
  size_t        i;
  char		**envcpy;

  i = 0;
  envcpy = malloc((std_split_size(env) + 1) * sizeof(char *));
  if (envcpy == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      envcpy[i] = malloc((std_strlen(env[i]) + 1) * sizeof(char));
      if (envcpy == NULL)
	{
	  while (i != 0)
	    {
	      free(envcpy[i - 1]);
	      i = i - 1;
	    }
	  free(envcpy);
	  return (NULL);
	}
      envcpy[i] = std_memcpy(envcpy[i], env[i], std_strlen(env[i]) + 1);
      i = i + 1;
    }
  envcpy[i] = NULL;
  return (envcpy);
}
