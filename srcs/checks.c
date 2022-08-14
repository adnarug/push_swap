/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:56:18 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 20:07:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Check for final sorted, returning 1, if sorted. */
int	check_for_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

/* Stack that can be rotated without pushing e.g 34512.
	Find min and then check that until null is increasing*/
int	check_raw_sorted(t_list **a)
{
	t_list	*temp;
	t_list	*min;

	temp = *a;
	min = search_min(a);
	while (min != NULL && min->next != NULL)
	{
		if (min->content < (min->next)->content)
			min = min->next;
		else
			return (0);
	}
	if (temp->content < min->content)
		return (0);
	min = search_min(a);
	while (temp != min && temp->next != min)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	check_repeats(int *arrayfor_check, int number, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (arrayfor_check[i] == number)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	checkis_digit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '+' && s[i] != '-')// Check if there is a non-digit
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check_limits(long int number)
{
	if(number > MAX_INT || number < MIN_INT)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}

