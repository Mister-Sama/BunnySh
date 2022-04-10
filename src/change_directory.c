/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** main - 2022
**
** *****************************************************************************
*/

#include        "bsh.h"

static void	std_change_pwd(const char		*path,
			       char			**env)
{
  size_t	i;
  size_t	index;
  char		*npwd;

  index = 0;
  i = std_get_env_value(env, "PWD=", &index);
  npwd = malloc((std_strlen(path) + std_strlen("PWD=") + 1) * sizeof(char));
  if (npwd == NULL)
    return;
  std_strcat(std_strcpy(npwd, "PWD="), path);
  free(env[i]);
  env[i] = npwd;
}

void		std_change_directory(const char		*str,
				     char		**env)
{
  size_t	i;
  size_t	index;
  char		*path;

  i = 0;
  index = 0;
  path = NULL;
  if (str == NULL)
    {
      while (env[i] != NULL && std_read_text(env[i], &index, "USER=") != true)
	i = i + 1;
      path = malloc(std_strlen(&(env[i][index])) + std_strlen("/home/") + 1 * sizeof(char));
      if (path == NULL)
	return;
      path = std_strcat(std_strcpy(path, "/home/"), &(env[i][index]));
      if (chdir(path) != -1)
	std_change_pwd(path, env);
      free(path);
      return;
    }
  std_change_pwd(str, env);
}
