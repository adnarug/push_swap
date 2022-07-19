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

void	ft_argv2list(char **nums, int count, t_num *head_p, int start);
t_num	*ft_lstlast(t_num *lst);
int		ft_lstsize(t_num *lst);
t_num	*ft_lstadd_back(t_num **lst, t_num *new);
t_num	*ft_lstnew(int content);
void	ft_lst_free(t_num *lst);
void	ft_print_lst(t_num *lst);
char	**ft_split(char const *s, char c, int *counter);
void	check_isdigit(char *s);
void 	clean_nums(char **nums, int length);
void	parsing_input(char *nums, int *count, t_num *latest_element);
void	ft_news_nums2list(char **nums, int count, t_num *head_p);
char	**typeof_input(char **nums, int *argc, int *start);
int		ft_isdigit(int c);
//void	check_dupes(char *s, int argc);
void	check_repeats(int *new_nums, int number, int count);
void	check_dupes(t_num *list, t_num *head_p);

#endif
