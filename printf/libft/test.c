#include "libft.h"
#include <stdio.h>

int main ()
{
	printf("The original: %ld\n", atoi("+50+"));
	printf("Mine: %ld \n", ft_atoi("+50+"));
	return (0);
}