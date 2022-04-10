/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** bsh - 2022
**
** *****************************************************************************
*/

#ifndef		__BSH_H__
#define		__BSH_H__

#include	<stddef.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	<malloc.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>

#define         MIN(a) ((a) >= 'A' && (a) <= 'Z') ? ((a) + ('a' - 'A')) : (a)

char            *std_read_stdin(void);

char            **std_split(const char			*str,
                            char			token);

void            *std_realloc(void			*ptr,
			     size_t			size);

size_t          std_strlen(const char			*str);

char            *std_strcat(char			*dest,
                            const char			*src);

char            *std_strcpy(char			*dest,
                            const char			*src);

void            *std_memcpy(void			*dest,
                            const void			*src,
                            size_t			n);

bool            std_read_text(const char		*str,
                              size_t			*index,
                              const char		*token);

int             std_exec_cmd(const char			*pathname,
                             char			*argv[],
			     char			*env[]);

void            std_print_split(char			**split);

void            std_free_split(char			**split);

size_t          std_split_size(char			**split);

int		std_puts(const char			*str);

bool            std_strcasecmp(const char		*str,
                               const char		*str2);

void            std_set_env_value(char			***split,
                                  char			**env);

void            std_init_cmd(char			**split_cmd,
                             char			**env);

void		std_change_directory(const char		*str,
				     char		**env);

size_t          std_get_env_value(char			**env,
                                  char			*value,
                                  size_t		*index);

char            **std_env_copy(char			**env);

#endif
