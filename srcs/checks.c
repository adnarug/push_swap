/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:56:18 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 13:56:59 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Check for final sorted, returning 1, if sorted. */
int	check_for_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while(temp->next != NULL)
	{
		if(temp->content < temp->next->content)
			temp = temp->next;
		else 
			return(0);
	}
	return (1);
}