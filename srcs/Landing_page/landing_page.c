#include "../includes/fdf.h"

static void	render_black(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j, i, BLACK_PIXEL);
			j++;
		}
		++i;
	}
}
int	render_exit(t_data *data)
{
	int		i;
	char	*hud[2];

	hud[0] = "       Do you really want to exit?       ";
	hud[1] = "     PRESS Y TO EXIT OR N TO HAVE FUN    ";
	render_black(&data->img);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	i = 0;
	while (i < 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 100,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	return (0);
}

int	render_landing(t_data *data)
{
	int i;
	char *hud[2];

	hud[0] = "       FDF of TVIEJO:       ";
	hud[1] = "  PRESS SPACE TO CONTINUE   ";
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	i = 0;
	while (i < 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 60,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	return (0);
}