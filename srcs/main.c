/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/30 13:43:32 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	(void)argc;
	data.arg = argv[1];
	map = create_map(data.arg);
	data.map = map;
	ft_init_view(&data, map);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf tviejo");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	//	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	//	mlx_destroy_display(data.mlx_ptr);
	//	free(data.mlx_ptr);
	//	ft_free_map(&map);
}
/*
int	main(int argc, char **argv)
{
		char    ***map;
		int     i;
		int     j;
		if (argc > 1)
		{
				map = create_map(argv[1]);
				j = 0;
				while (map[j] != NULL)
				{
						i = 0;
						while (map[j][i] != NULL)
						{
								printf("%s  ",map[j][i]);
								i++;
						}
						printf("\n");
						j++;
				}
		}
		return (0);
}*/
