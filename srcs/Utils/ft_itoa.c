/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:38 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 18:26:26 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static long int	ft_len(long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_convert(char *nbr_char, long int nb, long int leni)
{
	nbr_char[leni + 1] = '\0';
	while (nb > 0)
	{
		nbr_char[leni--] = (nb % 10 + 48);
		nb = nb / 10;
	}
}

static char	*ft_ltoa(long nb)
{
	long int	leni;
	char		*nbr_char;

	leni = ft_len(nb);
	nbr_char = (char *)malloc((leni + 2) * sizeof(char));
	if (nbr_char == NULL)
		return (NULL);
	if (nb < 0)
	{
		nbr_char[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
	{
		nbr_char[0] = '0';
		nbr_char[1] = '\0';
	}
	else
		ft_convert(nbr_char, nb, leni);
	return (nbr_char);
}

char	*ft_itoa(long nb)
{
	return (ft_ltoa(nb));
}

/*
#include <string.h>
#include <stdlib.h>
int	main(void)
{
	printf("%d\n", strcmp(ft_itoa(-456), "-456"));
	printf("%d\n", strcmp(ft_itoa(125), "125"));
	printf("%d\n", strcmp(ft_itoa(0), "0"));
	printf("%d\n", strcmp(ft_itoa(-2147483648), "-2147483648"));
	printf("%d\n", strcmp(ft_itoa(2147483647), "2147483647"));
	printf("%d\n", strcmp(ft_itoa(-5), "-5"));
	printf("%d\n", strcmp(ft_itoa(3), "3"));
	printf("%d\n", strcmp(ft_itoa(-0), "0"));
}
*/
