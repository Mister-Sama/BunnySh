/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** init_cmd - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

size_t		std_get_env_value(char		**env,
				  char		*value,
				  size_t	*index)

{
  size_t	i;

  i = 0;
  *index = 0;
  while (env[i] != NULL && std_read_text(env[i], index, value) != true)
    i = i + 1;
  return (i);
}
