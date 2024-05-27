/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/24 11:46:48 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_words(const char *str, char c)
{
	int	nb_words;
	int	i;

	nb_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != c)
			nb_words++;
		else if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int	ft_len_words(const char *str, char c)
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

static char	*ft_copy_line(const char **str, char c)
{
	char	*line;
	int		len_words;

	while (**str == c)
		++(*str);
	len_words = ft_len_words(*str, c);
	line = (char *)malloc((len_words + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *str, len_words + 1);
	*str += len_words;
	return (line);
}

static void	ft_free(char **str)
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

char	**ft_split(const char *str, char c)
{
	int		i;
	int		nb_words;
	char	**output;

	if (str == NULL)
		return (NULL);
	nb_words = ft_count_words(str, c);
	output = (char **)malloc((nb_words + 1) * sizeof(char *));
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
/*
int	main(void)
{
	char	*str = "qwertyubdbdbekjqkjkbjejdwbhjdbejbdqwwndwjwe";
	char	**output;
	int	i;

//	output = ft_count_words(str, charset);
//	printf("%d" , outputi);
//	output = ft_len_words(str, charset);
//      printf("%d" , output);
      
	output = ft_split("lorem ipsum dolor sit amet, consectetur ", ' ');
	i = 0;
	while (output != NULL && output[i] != NULL)
	{
        	printf("1: %s\n" , output[i]);
		i++;
	}
	ft_free(output);
	printf("\n");
	output = ft_split("  qwerty  azerty  ", ' ');
        i = 0;
        while (output[i] != NULL)
        {
                printf("2: %s\n" , output[i]);
                i++;
        }
	ft_free(output);
        printf("\n");
	output = ft_split(str, ' ');
        i = 0;
        while (output[i] != NULL)
        {
                printf("3: %s\n" , output[i]);
                i++;
        }
	ft_free(output);
	printf("\n");
//        output = ft_split(NULL, 'e');
//        i = 0;
//        while (output != NULL && output[i] != NULL)
//        {
//                printf("4: %s\n" , output[i]);
//                i++;
//        }
//	ft_free(output);
}*/
