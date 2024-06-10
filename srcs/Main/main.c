/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/10 17:05:19 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fdf_img(t_data data)
{
	data.page.landing_page = 1;
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	data.pixel = NULL;
	ft_init_view(&data, data.map);
	data.view = 1;
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 17, StructureNotifyMask, &ft_close, &data);
	mlx_hook(data.win_ptr, 4, ButtonPressMask, &handle_mouse_press, &data);
	mlx_hook(data.win_ptr, 5, ButtonReleaseMask, &handle_mouse_release, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	if (data.img.mlx_img != NULL)
		mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
}

static int	ft_fdf(char *argv)
{
	t_data	data;

	data.file = argv;
	data.parsed_data = 0;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (ft_putstr_fd("Mlx init error\n", 2), MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf tviejo");
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), ft_putstr_fd("Mlx error\n", 2),
			WINDOW_ERROR);
	data.map.map = NULL;
	data.pixel = NULL;
	ft_fdf_img(data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (ft_fdf(argv[1]));
	else
		return (ft_putstr_fd("Invalid argument number\n", 2), INVALID_ARGUMENT);
}
