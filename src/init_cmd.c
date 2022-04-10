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

void		std_init_cmd(char		**split_cmd,
			     char		**env)
{
  size_t	i;
  size_t	index;
  char		**split_env;
  char		*path;
  int		res;
  
  path = NULL;
  res = std_exec_cmd(split_cmd[0], split_cmd, env);
  i = std_get_env_value(env, "PATH=", &index);
  split_env = std_split(&env[i][index], ':');
  i = 0;
  while (split_env[i] != NULL && res == 255)
    {
      path = malloc((std_strlen(split_cmd[0]) +
		     std_strlen(split_env[i]) + 2) * sizeof(char));
      (path != NULL) ? path = std_strcat(std_strcpy(path, split_env[i]), "/") : 0;
      (path != NULL) ? path = std_strcat(path, split_cmd[0]) : 0;
      res = (path != NULL) ? std_exec_cmd(path, split_cmd, env) : res;
      (path != NULL) ? free(path) : 0;
      i = i + 1;
    }
  std_free_split(split_env);
}
