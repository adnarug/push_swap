#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_num
{
	int			*content;
	struct	s_num	*next;
}	t_num;

void *ft_argv2list(char **argv, int argc, t_num *a);

#endif
