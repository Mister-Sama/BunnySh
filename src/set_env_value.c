/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_env_value - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

static void	std_add_split(char		**split_env,
			      char		***split_cmd,
			      size_t		*index)
{
  char		**nsplit;

  nsplit = malloc((std_split_size(split_env) + std_split_size(*split_cmd)) * sizeof(char *));
  if (nsplit == NULL)
    return;
  std_memcpy(nsplit, (*split_cmd), *index * sizeof(char *));
  std_memcpy(&(nsplit[*index]), split_env, std_split_size(split_env) * sizeof(char *));
  std_memcpy(&(nsplit[*index + std_split_size(split_env)]), &((*split_cmd)[*index + 1]), (std_split_size(*split_cmd) - (*index) - 1) * sizeof(char *));
  nsplit[std_split_size(*split_cmd) + std_split_size(split_env) - 1] = NULL;
  *index = *index + std_split_size(split_env) - 1;
  free(split_env);
  free(*split_cmd);
  *split_cmd = nsplit;
}

void		std_set_env_value(char		***split,
				  char		**env)
{
  size_t	i;
  size_t	j;
  size_t	index;

  i = 0;
  while ((*split)[i] != NULL)
    {
      j = 0;
      index = 0;
      if ((*split)[i][0] == '$')
	{
	  while (env[j] != NULL && std_read_text
		 (env[j], &index, (&((*split)[i][1]))) != true)
	    j = j + 1;
	  if (env[j] != NULL)
	    {
	      free((*split)[i]);
	      std_add_split(std_split(&env[j][index + 1], ':'), split, &i);
	    }
	}
      i = i + 1;
    }
}
