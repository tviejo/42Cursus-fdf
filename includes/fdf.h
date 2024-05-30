/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/30 22:59:38 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

# define MLX_ERROR 1

# define BLACK_PIXEL 0x000000
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_3dcoor
{
	int		x;
	int		y;
	int		z;
}			t_3dcoor;

typedef struct s_2dcoor
{
	int		x;
	int		y;
	int		color;
}			t_2dcoor;

typedef struct s_map
{
	char	***map;
	int		x;
	int		y;
	int		z;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
	int		cur_img;
	int		zoom;
	int		rotax;
	int		rotay;
	int		rotaz;
	int		transx;
	int		transy;
	int		lenx;
	int		leny;
	int		lenz;
	char	*arg;
	int		colorb;
	int		colorl;
}			t_data;

typedef struct s_line
{
	t_2dcoor	begin;
	t_2dcoor        end;
	int		color;
}			t_line;

int     ft_multiple_color_change(int color, int n);
int     ft_parse_color(t_data data, char *str);
int			ft_free_map(t_map *map);
int			ft_color_change(int color);
void		ft_init_view(t_data *data, t_map map);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
void		img_pix_put(t_img *img, int x, int y, int color);
int			render_line(t_img *img, t_line line);
void		render_background(t_img *img, int color);
int			handle_keypress(int keysym, t_data *data);
int			render(t_data *data);
t_2dcoor	convertortho(int x, int y, int z, t_data *data, int color);
t_2dcoor	ft_rota(t_2dcoor point2D, int angle);
char		*get_next_line(int fd);
char		*ft_strncpy(char *dest, char *scr, int n);
void		ft_remove_returned(char *buffer);
int			get_first_line(char *buffer);
void		*ft_bzero(void *s, size_t n);
int			ft_is_new_line(char *buffer);
char		**ft_split(const char *str, char c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_atoi(const char *str);
t_map		create_map(char *argv);

#endif
