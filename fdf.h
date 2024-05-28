/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:50:56 by tviejo            #+#    #+#             */
/*   Updated: 2024/05/28 13:44:55 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
#include "mlx/mlx.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_img
{
        void    *mlx_img;
        char    *addr;
        int             bpp;
        int             line_len;
        int             endian;
}       t_img;

typedef struct s_2dcoor
{
        int     x;
        int     y;
}       t_2dcoor;

typedef struct s_data
{
        void    *mlx_ptr;
        void    *win_ptr;
        t_img   img;
        int             cur_img;
	int     zoom;
        int     rotax;
        int     rotay;
        int     rotaz;
        int     transx;
        int     transy;
}       t_data;

typedef struct s_line
{
        int     x1;
        int     y1;
        int     x2;
        int     y2;
        int color;
}       t_line;

typedef	struct	s_map
{
	char	***map;
	int	x;
	int	y;
}	t_map;

void    ft_init_view(t_data *data);
void	ft_putchar(char c);
void    ft_putnbr(int nb);
int	ft_strlen(char  *str);
void    ft_putstr(char  *str);
void    img_pix_put(t_img *img, int x, int y, int color);
int render_line(t_img *img, t_line line);
void    render_background(t_img *img, int color);
int     handle_keypress(int keysym, t_data *data);
int     render(t_data *data);
t_2dcoor        convertortho(int x, int y, int z, int angle, int zoom);
t_2dcoor        ft_rotax(t_2dcoor point2D, int angle);
char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *scr, int n);
void	ft_remove_returned(char *buffer);
int		get_first_line(char *buffer);
void	*ft_bzero(void *s, size_t n);
int		ft_is_new_line(char *buffer);
char	**ft_split(const char *str, char c);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_atoi(const char *str);
t_map	create_map(char *argv);

#endif
