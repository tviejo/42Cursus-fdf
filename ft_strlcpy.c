/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:30 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/24 12:16:38 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
