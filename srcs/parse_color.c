/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:46:42 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/31 20:21:40 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hexchartoint(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'A' && c <= 'F')
	{
		return (c - 'A' + 10);
	}
	else if (c >= 'a' && c <= 'f')
	{
		return (c - 'a' + 10);
	}
	else
	{
		return (-1);
	}
}

int	hexstringtoint(const char *hexString)
{
	int	result;
    int i;

	result = 0;
    i = 0;
	while ( hexString[i] != '\0')
	{
		result = result * 16 + hexchartoint(hexString[i]);
        i++;
	}
	return (result);
}

int	ft_parse_color(t_data data, char *str)
{
	int	cpt;

	cpt = 0;
	while (str[cpt] != ',' && str[cpt] != '\0')
		cpt++;
	if (str[cpt] != '\0')
		return (data.colorl + hexstringtoint(str + 2));
	if (atoi(str) > 0)
		return (ft_multiple_color_change(data.colorl, atoi(str)
				* data.gradientsize, 1));
	else
		return (ft_multiple_color_change(data.colorl, -atoi(str)
				* data.gradientsize, 2));
}
