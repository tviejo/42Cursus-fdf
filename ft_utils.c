/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:30 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 11:09:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_putstr(char	*str)
{
	if (str != NULL)
		write(1, &str, ft_strlen(str));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0)
		return (len_src);
	counter = 0;
	while (counter < size - 1 && src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter ++;
	}
	dest[counter] = '\0';
	return (len_src);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
        int     result;
        char    dest[] = "ABCD";
        char    src[] = "EFGH";

        result = ft_strlcpy(dest, src, 0);
        printf("%d", result);
	printf("\n%s", dest);
}
*/
