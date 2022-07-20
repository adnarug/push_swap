/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/20 15:24:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

//TODO: space in the end
int main(int argc, char **argv)
{
	t_num	*a;
	t_num	*b;
	int		i;

	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	argv = typeof_input(argv, &argc, &i);
	a = ft_lstnew(atoi(argv[i]));
	i += 1;
	ft_argv2list(argv, argc, a, i);
	//sa(a);
	//reassign_node(&a);
	rra(&a);
	ft_print_lst_a(a);
	ft_print_lst_b(b);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	system("leaks a.out");
	return (0);
}

void ft_argv2list(char **nums, int count, t_num *a, int start)
{
	int 	counter;
	t_num	*first;
	int		number;
	int		new_nums[count];
	
	number = 0;
	counter = 1;
	first = a;
	new_nums[0] = first->content;
	while(start < count)
	{
		check_isdigit(nums[start]);
		number = atoi(nums[start]);
		check_repeats(new_nums, number, count);
		new_nums[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number));
		start++;
		counter++;
	}
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

// void clean_nums(char **nums, int length)
// {
// 	int	i;
	
// 	i = 1;
// 	while(i < length)
// 	{
// 		free(nums[i]);
// 		nums[i] = NULL;
// 		i++;
// 	}	
// 	free(nums);
// 	nums = NULL;
// }

// void ft_news_nums2list(char **nums, int count, t_num *a)
// {
// 	int		i;
// 	t_num	*first;
// 	int		number;
	
// 	i = 0;
// 	number = 0;
// 	first = a;
// 	while(i < count)
// 	{
// 		number = atoi(nums[i]);
// 		first = ft_lstadd_back(&first, ft_lstnew(number));
// 		i++;
// 	}
// 	return ;
// }
