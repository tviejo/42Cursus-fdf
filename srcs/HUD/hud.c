/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:38:00 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/05 17:38:44 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_hud(t_data *data)
{
	int		i;
	char	*hud[9];

	hud[0] = "--------------------";
	hud[1] = "| R -< rotax  >+ E |";
	hud[2] = "| F -< rotay  >+ D |";
	hud[3] = "| V -< rotaz  >+ C |";
	hud[4] = "| Q -< transx >+ W |";
	hud[4] = "| A -< transy >+ S |";
	hud[4] = "| Z -< transx >+ X |";
	hud[5] = "| Z -< zoom   >+ X |";
	hud[6] = "|      party  >  P |";
	hud[7] = "|      reset  >  O |";
	hud[8] = "--------------------";
	i = 0;
	while (i < 9)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100 + i * 20,
			WHITE_PIXEL, hud[i]);
		i++;
	}
}
