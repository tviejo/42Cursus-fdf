/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:27 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/26 22:05:56 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int render_line(t_img *img, t_line line)
{
	double deltaX = line.x2 - line.x1; // 10
	double deltaY = line.y2 - line.y1; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = line.x1;
	double pixelY = line.y1;
	while (pixels)
	{
		img_pix_put(img, pixelX, pixelY, line.color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

t_2dcoor	convertortho(int x, int y, int z, int angle, int zoom)
{
    t_2dcoor point2D;

    double rad = angle * (M_PI / 180.0);
/*
    point2D.x = (x * zoom) * cos(rad) - (z * zoom) * sin(rad);
    point2D.y = y * zoom;

	printf("%d", z);
	point2D.x = (x * zoom) * cos(M_PI / 6);
	point2D.y = (x * zoom) * sin(M_PI / 6) + (y * zoom) * sin(M_PI / 6) - (z * zoom);
*/

	point2D.x = ((sqrt(3) / 2) * x - (sqrt(3) / 2) * z) * zoom;
	point2D.y = (0.5 * x + y + 0.5 * z) * zoom;

	

	return point2D;
}

int	render(t_data *data)
{
	t_2dcoor	end;
	t_2dcoor	begin;
	t_map		map;
	int	i;
	int	j;
	int	zoom = 50;
	int	offset = 200;
	int	angle = 0;

	render_background(&data->img, WHITE_PIXEL);
	map = create_map("test_simple");

	i = 0;
	while (i < map.x - 1)
	{
		j = 0;
		while (j < map.y)
		{
			begin = convertortho(i, j, atoi(map.map[i][j]), angle, zoom);
			end = convertortho(i + 1, j, atoi(map.map[i][j]), angle, zoom);
			render_line(&data->img, (t_line){ offset + begin.x, offset + begin.y, offset + end.x, offset + end.y, RED_PIXEL});
			j++;
		}
	i++;
	}
	j = 0;
	while (j < map.y - 1)
        {
                i = 0;
                while (i < map.x)
                {
                        begin = convertortho(i, j, atoi(map.map[i][j]), angle, zoom);
                        end = convertortho(i, j + 1, atoi(map.map[i][j]), angle, zoom);
                        render_line(&data->img, (t_line){ offset + begin.x, offset + begin.y, offset + end.x, offset + end.y, RED_PIXEL});
                        i++;
                }
        j++;
        }

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	main(void)
{
	t_data	data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
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

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
/*
int     main(int argc, char **argv)
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
