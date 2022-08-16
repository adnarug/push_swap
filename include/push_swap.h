/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:59:58 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 19:09:25 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../printf/ft_printf.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

//Input parsing - 3 statics
t_list	*input_parsing(char **argv, int *argc);
void	error_message(int error);
//checks - 0 statics
int		check_raw_sorted(t_list **a);
int		check_for_sorted(t_list **a);
void	check_repeats(int *arrayfor_check, int number, int counter);
void	checkis_digit(char *s);
void	check_limits(long int number);
//Duplicate_lst - 1 statics
t_list	*ft_lst_duplicate(t_list **a);
//Lst_uitls - 0 sattics
void	ft_lst_free(t_list *lst);
t_list	*search_by_postion(t_list *stack, int position);
void	move_to_b(t_list **a, t_list **b);
void	give_index(t_list **stack);
//Presorting - 2 statics
void	final_sort(t_list **a);
t_list	*sorting(t_list **a);
void	lst_indexing(t_list **a, t_list *presorted_a);
//Presorting utils - 0 statics
t_list	*lst_swap(t_list **first, t_list **second);
t_list	*scan_left(t_list **a, t_list *mid_point);
t_list	*search_midpoint(t_list **a);
t_list	*scan_right(t_list *mid_point);
void	move_from_a_to_b(t_list **a, t_list **b, t_list *element);
//Rotating stacks - 2 statics
void	executing_rrs(t_list **a, t_list **b, t_list *to_move);
void	rotating_b(t_list **b, t_list *node_to_move);
void	rotating_a(t_list **a, t_list *target_spot);
//Move process
t_list	*search_cheapest_move(t_list **b);
int		finding_rrs(t_list *to_move, t_list *target);
void	move_process(t_list **a, t_list **b);
int		distance_to_move(t_list **stack, t_list *node);
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
//Instructons utils
t_list	*reassign_front_node(t_list **list);
t_list	*reassign_back_node(t_list **list);
void	ss(t_list *a, t_list *b);
void	push_above_median(t_list **a, t_list **b, t_list *median, t_list *max);
void	push_below_median(t_list **a, t_list **b, t_list *median, t_list *min);
//Sorting
void	sort_triple(t_list **stack);
void	sorting_small_stack(t_list **a, t_list **b);
void	stacks_sorting(t_list **a, t_list **b);
void	presorting(t_list **a);
//Score
void	presorting_check(t_list **a);
void	scoring(t_list **a, t_list **b);
t_list	*target_spot_in_a(t_list **a, t_list *node);
//Stats
t_list	*search_min(t_list **a);
t_list	*search_max(t_list **a);
t_list	*search_median(t_list **a);

#endif
