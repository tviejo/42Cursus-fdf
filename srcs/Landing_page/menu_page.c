/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:26:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 16:26:12 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*ft_res(char const *s1, char s2, char *ptr)
{
	int	size_s1;

	if (s1 != NULL)
	{
		size_s1 = 0;
		while (s1[size_s1] != '\0')
			size_s1++;
	}
	else
		size_s1 = 0;
	ptr = malloc((size_s1 + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[size_s1] = s2;
	ptr[size_s1 + 1] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char s2)
{
	char	*ptr;

	ptr = NULL;
	ptr = ft_res(s1, s2, ptr);
	return (ptr);
}
