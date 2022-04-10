/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** main - 2022
**
** *****************************************************************************
*/

#include	"bsh.h"

int		main(int        argc __attribute__((__unused__)),
		     char       *argv[] __attribute__((__unused__)),
		     char       **env)
{
  char		*cmd;
  char		**split_cmd;
  char		**envcpy;

  cmd = NULL;
  signal(SIGINT, SIG_IGN);
  envcpy = std_env_copy(env);
  if (envcpy == NULL)
    return (-1);
  while (std_strcasecmp(((cmd = std_read_stdin()) == NULL) ? "exit" : cmd, "exit") != true)
    {
      split_cmd = std_split(cmd, ' ');
      if (split_cmd != NULL)
	{
	  std_set_env_value(&split_cmd, envcpy);
	  (std_strcasecmp(split_cmd[0], "cd") == true) ?
	    std_change_directory(split_cmd[1], envcpy) : std_init_cmd(split_cmd, envcpy);
	  std_free_split(split_cmd);
	}
      (cmd != NULL) ? free(cmd) : 0;
    }
  std_free_split(envcpy);
  (cmd != NULL) ? free(cmd) : 0;
  return (0);
}
