#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../printf/ft_printf.h"

// typedef struct t_list
// {
// 	int			content;
// 	struct	s_list	*next;
// }	t_list;

void	ft_argv2list(char **nums, int count, t_list *a, int start);
void	ft_lst_free(t_list *lst);
void	ft_print_lst_a(t_list *a);
void	ft_print_lst_b(t_list *b);
void	check_isdigit(char *s);
void 	clean_nums(char **nums, int length);
void	parsing_input(char *nums, int *count, t_list *latest_element);
void	ft_news_nums2list(char **nums, int count, t_list *a);
char	**typeof_input(char **nums, int *argc, int *start);
void	check_repeats(int *new_nums, int number, int count);
void	check_dupes(t_list *list, t_list *a);
void    sorting(t_list **a, t_list **b);
//Libft
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new, int *counter);
t_list	*ft_lstnew(int content);
t_list 	*ft_lstlast(t_list *lst);
int		ft_isdigit(int c);
//char	**ft_split(char const *s, char c, int *counter);
//Instructions
void	sa(t_list *a);
void	pa(t_list **a, t_list **b);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
t_list	*reassign_front_node(t_list **b);
t_list	*reassign_back_node(t_list **list);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);





#endif
