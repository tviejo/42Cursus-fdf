/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:46:42 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/30 23:14:46 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

int hexStringToInt(const char* hexString) {
    int result = 0;
    for (int i = 0; hexString[i] != '\0'; i++) {
        result = result * 16 + hexCharToInt(hexString[i]);
    }
    return result;
}

int	ft_parse_color(t_data data, char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != ',' && str[cpt] != '\0')
		cpt++;
	if (str[cpt] != '\0')
		return (data.colorl + hexStringToInt(str + 2));
	return (ft_multiple_color_change(data.colorl, atoi(str) * 10000));
}
