#include "../includes/fdf.h"

int	handle_mouse_press(int keysym, int x, int y, t_data *data)
{
	if (keysym == 4)
		data->inter.zoom += 1;
	if (keysym == 5)
		if (data->inter.zoom > 1)
			data->inter.zoom -= 1;
	if (keysym == 1)
	{
		data->inter.mouser = 1;
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
	if (keysym == 3)
	{
		data->inter.mousel = 1;
		data->inter.mousex = x;
		data->inter.mousey = y;
	}
	return (0);
}

int	handle_mouse_release(int keysym, int x, int y, t_data *data)
{
	x++;
	y++;
	if (keysym == 1)
	{
		data->inter.mouser = 0;
	}
	if (keysym == 3)
	{
		data->inter.mousel = 0;
	}
	return (0);
}