/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/24 11:47:06 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *scr, int n)
{
	int	i;

	i = 0;
	if (scr != NULL && dest != NULL)
	{
		while (i < n && scr[i] != '\0')
		{
			dest[i] = scr[i];
			i++;
		}
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_remove_returned(char *buffer)
{
	int		i;
	int		n;

	n = get_first_line(buffer);
	i = n;
	while (buffer[i] != '\0')
	{
		buffer[i - n] = buffer[i];
		i++;
	}
	i = i - n;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

int	get_first_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

int	ft_is_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
