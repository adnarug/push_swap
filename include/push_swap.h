#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../printf/ft_printf.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648

//Push_Swap
// void	ft_argv2list(char **nums, int count, t_list *a, int start);
void	ft_lst_free(t_list *lst);
void	ft_print_lst_a(t_list *a);
void	ft_print_lst_b(t_list *b);
void	clean_nums(char **nums, int length);
void	parsing_input(char *nums, int *count, t_list *latest_element);
void	ft_news_nums2list(char **nums, int count, t_list *a);
void	check_dupes(t_list *list, t_list *a);
void    lst_indexing(t_list **a, t_list *presorted_a);
void    ft_default_struct(t_list **b, int total_count);
void    decrease_index(t_list **lst, int flag_for_ttl);
void	increase_index(t_list **lst, int flag_for_ttl);
t_list	*search_min(t_list **a);
t_list	*search_max(t_list **a);
t_list	*search_median(t_list **a);
int 	check_for_sorted(t_list **a);
void	sort_triple(t_list **a);
int		check_raw_sorted(t_list **a);
void    give_index(t_list **stack);
t_list	*input_parsing(char **argv,int *argc);
void	presorting_check(t_list **a);
void	free_stacks(t_list **a, t_list **b);
//int	no_of_inputs(t_list **a, int *argc);
void	move_min_to_b(t_list **a, t_list **b, t_list *min);
t_list	*sorting(t_list **a);
void    move_to_b(t_list **a, t_list **b);
void	scoring(t_list **a, t_list **b);
void	move_process(t_list **a, t_list **b);
t_list  *target_spot_in_a(t_list **a, t_list *node);
void	rotating_a(t_list **a, t_list *target_spot);
void	final_sort(t_list **a);
void	presorting(t_list **a);
void	stacks_sorting(t_list **a, t_list **b);
void	free_stacks(t_list **a, t_list **b);
void	sorting_stack_of_5(t_list **a, t_list **b);
void	move_process_for_5(t_list **a, t_list **b);
t_list	*target_spot_in_b(t_list **a, t_list *node);
void	move_process_for_5_back(t_list **a, t_list **b);
void move_from_a_to_b(t_list **a, t_list **b, t_list *element);
t_list	*search_by_postion(t_list *stack, int position);
//Presorting utils
t_list	*lst_swap(t_list **first, t_list **second);
t_list *scan_left(t_list **a, t_list *mid_point);
t_list	*search_midpoint(t_list **a);
t_list *scan_right(t_list *mid_point);
void	lst_copy_content(t_list **src, t_list **dst);
t_list	*ft_lst_duplicate(t_list **a);
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
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
