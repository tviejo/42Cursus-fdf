#include "../includes/fdf.h"

int	ft_sinus(int i, int j, t_data *data)
{
	if (data->phase != 0)
		return (data->map.map[i][j][0] * sin(((j * 10) + data->phase) / 10));
	else
		return (data->map.map[i][j][0]);
}