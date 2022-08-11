/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:28:50 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/11 20:04:34 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char				z;
	const char			*p_c;

	z = c;
	p_c = s;
	while (*p_c != '\0' || z == '\0')
	{
		if (*p_c == z)
			return ((char *)p_c);
		p_c++;
	}
	return (NULL);
}

// int main()
// {
// 	if (ft_strchr("	+502+", '	') != NULL)
// 		write( 1, "1", 1);
// 	else
// 		write (1, "0", 1);
// 	return(0);
// }
