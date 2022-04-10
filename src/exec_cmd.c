/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** exec_cmd - 2022
**
** *****************************************************************************
*/

#include	"bsh.h"

int		std_exec_cmd(const char		*pathname,
			     char		*argv[],
			     char		*env[])
{
  pid_t		fork_res;
  int		stat;
  int		code;

  fork_res = fork();
  if (fork_res == 0)
    {
      execve(pathname, argv, env);
      exit(-1);
    }
  else
    {
      waitpid(fork_res, &stat, 0);
      code = WEXITSTATUS(stat);
    }
  return (code);
}
