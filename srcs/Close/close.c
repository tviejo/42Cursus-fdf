/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:26:10 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/08 15:36:34 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
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


int	ft_free_img(t_data *data)
{
	int	i;
	int	size;

	if (data->pixel != NULL)
	{
		size = WINDOW_WIDTH;
		if (WINDOW_HEIGHT > size)
			size = WINDOW_HEIGHT;
		i = 0;
		while (i < size)
		{
			free(data->pixel[i]);
			i++;
		}
		free(data->pixel);
	}
	return (0);
}

int	ft_close(t_data *data)
{
	if (data->map.map)
		ft_free_map(&data->map);
	if (data->pixel != NULL)
		ft_free_img(data);
	if (data->img.mlx_img && data->mlx_ptr && data->img.addr)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	exit (0);
}
