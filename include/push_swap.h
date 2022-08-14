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
//checks - 0 statics
int		check_raw_sorted(t_list **a);
int		check_for_sorted(t_list **a);
t_list	*reassign_front_node(t_list **list);
t_list	*reassign_back_node(t_list **list);
//Duplicate_lst - 1 statics
t_list	*ft_lst_duplicate(t_list **a);
//Lst_uitls - 0 sattics
void	ft_lst_free(t_list *lst);
t_list	*search_by_postion(t_list *stack, int position);
void	move_to_b(t_list **a, t_list **b);
void	give_index(t_list **stack);
//Presorting - 2 statics
t_list	*sorting(t_list **a);
void	lst_indexing(t_list **a, t_list *presorted_a);
//Presorting utils - 0 statics
t_list	*lst_swap(t_list **first, t_list **second);
t_list	*scan_left(t_list **a, t_list *mid_point);
t_list	*search_midpoint(t_list **a);
t_list	*scan_right(t_list *mid_point);
void	lst_copy_content(t_list **src, t_list **dst);
t_list	*ft_lst_duplicate(t_list **a);
//Rotating stacks - 2 statics
void	executing_rrs(t_list **a, t_list **b, t_list *to_move);
void	rotating_b(t_list **b, t_list *node_to_move);
void	rotating_a(t_list **a, t_list *target_spot);
//Move process
t_list	*search_cheapest_move(t_list **b);
int		finding_rrs(t_list *to_move, t_list *target);
void	move_process(t_list **a, t_list **b);
//Instructions_a
void	sa(t_list *a);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);
void	rrr(t_list **a, t_list **b);
//Instructions_b
void	sb(t_list *b);
void	pb(t_list **a, t_list **b);
void	rb(t_list **b);
void	rrb(t_list **b);
void	rr(t_list **a, t_list **b);

#endif
