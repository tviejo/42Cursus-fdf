/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/08 10:24:14 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_words(char *str, char c)
{
	int	nb_words;
	int	i;

	nb_words = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (i == 0 && str[i] != c)
			nb_words++;
		else if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int	ft_len_words(char *str, char c)
{
	int	i;
	int	len_words;

	len_words = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		len_words++;
		i++;
	}
	return (len_words);
}

static int	*ft_copy_line(char **str, char c)
{
	int	*line;
	int	len_words;

	while (**str == c)
		++(*str);
	len_words = ft_len_words(*str, c);
	if (len_words < 2)
		len_words = 2;
	line = (int *)malloc(3 * sizeof(int));
	if (line == NULL)
		return (NULL);
	line[0] = ft_atoi(*str);
	line[1] = hexstringtoint(*str);
	line[2] = '\0';
	*str += len_words;
	return (line);
}

static void	ft_free(int **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	**ft_split_map(char *str, char c, int nb_words)
{
	int	i;
	int	**output;

	if (str == NULL)
		return (NULL);
	output = (int **)malloc((nb_words + 1) * sizeof(int *));
	if (output != NULL)
	{
		i = 0;
		output[nb_words] = NULL;
		while (i < nb_words)
		{
			output[i] = ft_copy_line(&str, c);
			if (output[i] == NULL)
			{
				ft_free(output);
				output = NULL;
				break ;
			}
			i++;
		}
	}
	return (output);
}
