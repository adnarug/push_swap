/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/16 13:04:03 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


int main(int argc, char **argv)
{
	t_num	*head_p;
	t_num	*check;
	
	if (argc < 2)
		return (0);
	head_p = ft_lstnew(atoi(argv[1]));
	ft_argv2list(argv, argc, head_p);
	check = ft_lstlast(head_p);
	printf("the first element is: %d \n", head_p->content);
	printf("the last element is: %d", check->content);
	//printf ("Checking: %d", check->content);
	// a = head_p;
	// while (a != NULL)
	// {
	// 	printf ("%d", a->content);
	// 	a = a->next;
	// }
	return (0);
}

void *ft_argv2list(char **nums, int count, t_num *head_p)
{
	int		i;
	t_num	*first;
	
	i = 2;
	// first = malloc(sizeof(t_num));
	first = head_p;
	while (count > i)
	{
		first = ft_lstadd_back(&first, ft_lstnew(atoi(nums[i])));
		i++;
	}
	return (first);
}
