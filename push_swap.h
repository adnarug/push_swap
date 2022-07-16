#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_num
{
	int			content;
	struct	s_num	*next;
}	t_num;

void	*ft_argv2list(char **nums, int count, t_num *head_p);
t_num	*ft_lstlast(t_num *lst);
int		ft_lstsize(t_num *lst);
t_num	*ft_lstadd_back(t_num **lst, t_num *new);
t_num	*ft_lstnew(int content);



#endif
