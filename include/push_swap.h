#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../printf/ft_printf.h"

//Push_Swap
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
void    ft_default_struct(t_list **b, int total_count);
void    decrease_index(t_list **lst, int flag_for_ttl);
void    increase_index(t_list **lst, int flag_for_ttl);
void    search_min(t_list **a, t_list   **b);

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
void    rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);





#endif
