#include "../includes/fdf.h"

static char	*ft_res(char const *s1, char s2, char *ptr)
{
	int	size_s1;

	if (s1 != NULL)
	{
		size_s1 = 0;
		while (s1[size_s1] != '\0')
			size_s1++;
	}
	else
		size_s1 = 0;
	ptr = malloc((size_s1 + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[size_s1] = s2;
	ptr[size_s1 + 1] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char s2)
{
	char	*ptr;

	ptr = NULL;
		ptr = ft_res(s1, s2, ptr);
	return (ptr);
}

int	render_menu(t_data *data)
{
	int		i;
	char	*hud[3];

	hud[0] = "              ";
	if (data->file != NULL)
		hud[0] = "               Map already given       ";
	hud[1] = "             do you want to load another map?    ";
	hud[2] = "press enter to load a the new map or space to stay whit the old one";
	render_black(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	i = 0;
	while (i < 3)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2 - 100,
			WINDOW_HEIGHT / 2 + i * 20 - 20, WHITE_PIXEL, hud[i]);
		i++;
	}
	return (0);
}
