/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/23 14:17:58 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: 1. space in the end 2. lst_add back conflict 3. Indexes (init and actual) to decide the min moves to get to instructions
int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	b = malloc(sizeof(t_list));
	i = 1;
	if(argc < 2)
		return (0);
	argv = typeof_input(argv, &argc, &i);
	a = ft_lstnew(atoi(argv[i]));
	if (i != 0) // TODO: passing of argc needs optimization
		a->total_count = argc - 1;
	else
		a->total_count = argc;
	i += 1;
	ft_default_struct(&b, a->total_count);
	ft_argv2list(argv, argc, a, i);
	//sorting(&a ,&b);
	ra(&a);
	ft_print_lst_a(a);
	ft_print_lst_b(b);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	system("leaks push_swap");
	return (0);
}

void ft_argv2list(char **nums, int argc, t_list *a, int start)
{
	int 	counter;
	t_list	*first;
	int		number;
	int		*new_nums;;
	
	number = 0;
	counter = 1;
	first = a;
	new_nums = ft_calloc(argc, sizeof(int));
	if (new_nums == NULL)
		return ;
	new_nums[0] = first->content;
	while(start < argc)
	{
		check_isdigit(nums[start]);
		number = atoi(nums[start]);
		check_repeats(new_nums, number, argc);
		new_nums[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number), counter);
		start++;
		counter++;
	}
	free(new_nums);
	new_nums = NULL;
}

void check_repeats(int *new_nums, int number, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (new_nums[i] == number)
		{
			write (2, "Error", 6);
			exit (1);
		}
		i++;
	}
}

void	check_isdigit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '+' && s[i] != '-' && s[i] == 0)// Check if there is a non-digit
		{
			write (2, "Error", 6);
			exit(1);
		}
		i++;
	}
}

char **typeof_input(char **nums, int *argc, int *i)
{
	int		counter;

	counter = 0;
	if(strchr(nums[1], ' ') != NULL)
	{
		nums = ft_split(nums[1], ' ', &counter);
		*argc = counter;
		*i = 0;
	}
	return(nums);
}

void sorting(t_list **a, t_list **b)
{
	pb(a, b);
	while (*a != NULL)
	{
		if (*b == NULL)
			pb (a, b);
		if ((*a)->content > (*b)->content)
			pb(a, b);
		else
		{
			pa(a, b);
			ra(a);
		}
	}
	while (*b != NULL)
		pa(a, b);
}

// Search for the min algo; Indexes and translation of the indeces
void search_min(t_list **a)
{
	t_list	*min;
	
	min = *a;
	*a = (*a)->next;
	while(*a != NULL)
	{
		if(min->content > (*a)->content)
			min = *a;
		else
			*a = (*a)->next;
	}
}
