/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/22 17:56:19 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: 1. space in the end 2. lst_add back conflict 3. Indexes (init and actual) to decide the min moves to get to instructions
int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	argv = typeof_input(argv, &argc, &i);
	ft_default_struct(a, b, &argc);
	a = ft_lstnew(atoi(argv[i]));
	i += 1;
	ft_argv2list(argv, argc, a, i);
	//sorting(&a ,&b);
	ft_print_lst_a(a);
	ft_print_lst_b(b);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	//system("leaks a.out");
	return (0);
}

void ft_argv2list(char **nums, int count, t_list *a, int start)
{
	int 	counter;
	t_list	*first;
	int		number;
	int		*new_nums;;
	
	number = 0;
	counter = 1;
	first = a;
	new_nums = ft_calloc(count, sizeof(int));
	new_nums[0] = first->content;
	while(start < count)
	{
		check_isdigit(nums[start]);
		number = atoi(nums[start]);
		check_repeats(new_nums, number, count);
		new_nums[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number), &counter);
		start++;
		counter++;
	}
	free(new_nums);
}

void check_repeats(int *new_nums, int number, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
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
		if (ft_isdigit(s[i]) == 0 && s[i] != '+' && s[i] != '-' && s[i] != 0)// Check if there is a non-digit
		{
			write (2, "Error", 6);
			exit(1);
		}
		i++;
	}
}

char **typeof_input(char **nums, int *argc, int *start)
{
	int		counter;

	counter = 0;
	if(strchr(nums[1], ' ') != NULL)
	{
		nums = ft_split(nums[1], ' ', &counter);
		*argc = counter;
		*start = 0;
	}
	return (nums);
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

void ft_default_struct(t_list **a, t_list **b, int *argc)
{
	(*a)->content = 0;
	(*a)->init_index = 0;
	(*a)->index = 0;	
	(*a)->total_count = *argc;

	(*b)->content = 0;
	(*b)->init_index = 0;
	(*b)->index = 0;
	(*b)->total_count = *argc;
}