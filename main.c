/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/13 17:40:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
1. Check argc
2. Go through the arguments and check if:
	- less then 2
	- there is 0
	- there is a duplicate
3. If it is in brackets transorm into a normal input
4. Code the instructions
5. Decide on the algorithm
6. Test test test 
*/
int main(int argc, char **argv)
{
	t_num *a;
	int c = argc;
	void	*head_p;

	a = malloc(sizeof(t_num));
	if (argc < 2)
		return (0);
	head_p = ft_argv2list(argv, c, a);
	a = head_p;
	while (a != NULL)
	{
		printf ("%d", (int)a->content);
		a = a->next;
	}
	return (0);
}

void *ft_argv2list(char **argv, int c, t_num *a)
{
	int		i;
	void	*head_p;
	
	i = 1;
	head_p = &(a->content);
	while ((c - 1) > i)
	{
		a->content = *argv[i];
		if (*argv[i + 1] != '\0')
			a->next = (void*)argv[i + 1];
		else
			a->next = NULL;
		a = a->next;
		i++;
	}
	return (head_p);
}
