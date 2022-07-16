/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/16 19:50:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


int main(int argc, char **argv)
{
	t_num	*head_p;
	// t_num	*check;
	
	if (argc < 2)
		return (0);
	head_p = ft_lstnew(atoi(argv[1]));
	ft_argv2list(argv, argc, head_p);
	// check = ft_lstlast(head_p);
	// printf("the first element is: %d \n", head_p->content);
	// printf("the last element is: %d", check->content);
	// printf ("Checking: %d", check->content);
	ft_print_lst(head_p);
	ft_lst_free(head_p);
	head_p = NULL;
	// system("leaks a.out");
	return (0);
}

void *ft_argv2list(char **nums, int count, t_num *head_p)
{
	int		i;
	t_num	*first;
	int		number;
	
	i = 2;
	number = 0;
	first = head_p;
	while (count > i)
	{
		input_check(nums[i]);
		number = atoi(nums[i]);
		first = ft_lstadd_back(&first, ft_lstnew(atoi(nums[i])));
		i++;
	}
	return (first);
}

void	input_check(char *s, t_num *head_p)
{
	int	*counter;
	int i;
	int **after_split;

	counter = sizeof(int);
	*counter = 0;
	i = 0;
	if (*s < '0' || *s > '9')
	{
		write (2, "Error", 6);
		exit(1);
	}
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			after_split = ft_split(s, ' ', counter);
		i++;
	}
	ft_argv2list(after_split, *counter, ft_lstlast(head_p))
	return ;
}