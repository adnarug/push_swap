/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:08:29 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/29 13:16:24 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	no_of_inputs(int *argc)
{
	if (argc <= 5)
		return(1);
	else if (argc > 5 && argc <= 100)
		return(2);
	else if (argc > 100)
		return(3);
}

void sorting_small(t_list **a, t_list **b)
{
	
}