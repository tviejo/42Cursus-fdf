/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/06 18:38:27 by tviejo           ###   ########.fr       */
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

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define BLACK_PIXEL 0x000000
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

# define BUFFER_SIZE 100000

# define INVALID_ARGUMENT 1
# define INVALID_READ 2
# define WINDOW_ERROR 3
# define MLX_ERROR 4
# define SUCCESS 0

# define ISOMETRIC 1
# define PERSPECTIVE 2
/*
enum e_fdf_state {error = -1, success_windows, succe};
*/
typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_3dcoor
{
	int			x;
	int			y;
	int			z;
}				t_3dcoor;

typedef struct s_render
{
	double		deltax;
	double		deltay;
	double		pixelx;
	double		pixely;
}				t_render;

typedef struct s_2dcoor
{
	int			x;
	int			y;
	int			color;
	int			z;
}				t_2dcoor;

typedef struct s_line
{
	t_2dcoor	begin;
	t_2dcoor	end;
	int			color;
}				t_line;

typedef struct s_map
{
	int			***map;
	int			x;
	int			y;
	int			zmin;
	int			zmax;
}				t_map;

typedef struct s_inter
{
	int			zoom;
	int			rotax;
	int			rotay;
	int			rotaz;
	int			transx;
	int			transy;
	int			transz;
	int			lenx;
	int			leny;
	int			lenz;
	int			colorb;
	int			colorl;
	int			gradientspeed;
	int			partymode;
	float		gradientsize;
	int			view;
}				t_inter;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	t_inter		inter;
	int			cur_img;
	char		*arg;
}				t_data;

void			ft_put_hud(t_data *data);
int				ft_color_to_rgb(int r, int g, int b);
u_int8_t		getred(int rgb);
u_int8_t		getblue(int rgb);
u_int8_t		getgreen(int rgb);
int				ft_atoi(char *str);
int				hexstringtoint(const char *hexString);
int				ft_color_rchange(int color);
int				ft_nb_color_a_to_b(int colorbegin, int colorend);
int				ft_ncolor_change(int color, int n, int mode);
unsigned int	ft_parse_color(t_data data, int *zcolor);
int				ft_free_map(t_map *map);
int				ft_color_change(int color);
void			ft_init_view(t_data *data, t_map map);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *str, int fd);
void			img_pix_put(t_img *img, int x, int y, int color);
int				render_line(t_img *img, t_line line);
void			render_background(t_img *img, int color);
int				handle_keypress(int keysym, t_data *data);
int				render(t_data *data);
t_2dcoor		convert3dto2d(int x, int y, int z, t_data *data);
t_3dcoor		ft_rotax(t_3dcoor point3D, t_data *data);
t_3dcoor		ft_rotay(t_3dcoor point3D, t_data *data);
t_3dcoor		ft_rotaz(t_3dcoor point3D, t_data *data);
char			*get_next_line(int fd);
char			*ft_strncpy(char *dest, char *scr, int n);
void			ft_remove_returned(char *buffer);
int				get_first_line(char *buffer);
void			*ft_bzero(void *s, size_t n);
int				ft_is_new_line(char *buffer);
int				ft_count_words(char *str, char c);
int				**ft_split_map(char *str, char c, int nb_words);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_itoa(int *str);
t_map			create_map(char *argv);
void			ft_put_line(t_data *data);
bool			ft_pixel_is_printable(int pixelX, int pixelY);
int				ft_color_line(t_line line, int pixels);
void			ft_close(t_data *data);

#endif
