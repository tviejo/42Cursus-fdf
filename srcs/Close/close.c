/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:26:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/04 16:27:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_close(t_data *data)
{
	ft_free_map(&data->map);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
}

int	ft_free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != NULL)
		{
			free(map->map[i][j]);
			j++;
		}
		free(map->map[i]);
		i++;
	}
	free(map->map);
	return (0);
}
