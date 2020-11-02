/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:32:06 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 23:23:45 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <float.h>
# include <errno.h>
# include "mlx.h"
# include <stdio.h>
# include "../gnl/get_next_line.h"

# define TILE_SIZE 64
# define A "CUB3D"
# define SCALE  1
# define RAD(x) x * M_PI / 180
# define DEG(x) x * 180 / M_PI
# define FOV_ANG RAD(60)
# define NUM_RAYS g_win_width
# define S "screenshot.bmp"

int				g_win_width;
int				g_win_height;
char			**g_codemap;
int				g_codelen;
int				g_line;
int				g_v;
int				g_lol;
int				g_len;
int				g_count;
char			*g_file;
char			*g_no;
char			*g_so;
char			*g_we;
char			*g_ea;
char			*g_sp;
int				g_screen;
int				g_ccomma;
int				g_cnum;
int				g_fcomma;
int				g_fnum;

typedef	struct	s_bin{
	void		*mlx;
	void		*win;
	float		wall_height;
}				t_bin;

typedef	struct	s_player{
	float		x;
	float		y;
	float		newx;
	float		newy;
	float		pect;
	float		rat_ang;
	float		rot_spd;
	float		move_spd;
	float		radius;
	float		turn_dir;
	float		walk_dir;
	float		to_up;
	char		d;
}				t_player;

typedef struct	s_img{
	void		*img;
	int			*data;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_ray
{
	float		h_wallhitx;
	float		h_wallhity;
	float		distance;
	float		v_wallhitx;
	float		v_wallhity;
	float		horz_hitdis;
	float		vert_hitdis;
	float		wallhitx;
	float		wallhity;
	float		n_htx;
	float		n_hty;
	float		n_vtx;
	float		n_vty;
	int			f_h;
	int			was_v;
	int			f_v;
	int			s_h;
	int			s_v;
}				t_ray;

typedef struct	s_txt{
	float		txt_width;
	float		txt_height;
	float		*walltxt;
	int			*buff[4];
	int			offset_x;
	int			offset_y;
}				t_txt;

typedef struct	s_spt{
	int			*buff;
	float		x;
	float		y;
	float		x_off;
	float		y_off;
	float		size;
	float		dis;
}				t_spt;

typedef	struct	s_read{
	int			width;
	int			height;
	int			error;
	int			color_f;
	int			color_c;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_read;

typedef	struct	s_screen{
	int32_t			width;
	int32_t			height;
	uint16_t		bitcount;
	int				width_in_bytes;
	uint32_t		bisize;
	uint32_t		imagesize;
	uint32_t		bfoffbits;
	uint32_t		filesize;
	uint16_t		biplanes;
	unsigned char	header[54];
	unsigned char	*buf;
	int				fd;
	int				row;
	int				col;
}				t_screen;

typedef struct	s_bitmap
{
	unsigned int	file_size;
	unsigned int	pd_offset;
	unsigned int	header_size;
	unsigned int	image_width;
	unsigned int	image_height;
	unsigned int	image_size;
	unsigned short	planes;
	unsigned short	bpp;
	int				width_in_bytes;
}				t_bitmap;

struct			s_rgb
{
	int			r;
	int			g;
	int			b;
};

typedef	struct	s_data{
	t_bin		bin;
	t_player	player;
	t_img		img;
	t_ray		ray[5121];
	t_read		file;
	t_txt		txt;
	t_spt		*sprite;
	t_screen	scrn;
	int			scr;
	float		top_wall;
	float		top;
	int			nb;
	int			isright;
	int			isdown;
	int			*s_buff;
	int			len_s;
	int			len_no;
	int			len_so;
	int			len_ea;
	int			len_we;
}				t_data;

int				screen(t_data *data);
void			scrn_data(t_data *data, int x);
void			screen_init(t_data *data, unsigned char *header);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				draw(t_data *data);
void			first_strp(t_data *data, char **argv, int nb);
void			ft_putstr_fd(char *s, int fd);
int				read_line(int fd, char **line);
char			*ft_strstr(char *str, char *to_find);
int				to_skip(char *s);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen1(const char *s);
char			*ft_strdup1(const char *src, t_data *data);
void			rect2_txt(t_data *data, int jj, void *txt_img);
int				ft_atoi(const char *str);
int				digit_len(int nbr);
void			to_v(t_ray *ray, int id);
void			to_h(t_ray *ray, int id);
float			veta(float x, float y, float m, float n);
void			min_value_ray(t_ray *ray, t_player player, int id);
int				check_1(char *s);
int				check_0(char *s);
int				file_error(t_data *data, int fd);
void			me_error(char *str);
void			draw_circle(t_data *data);
void			draw_circle1(float x, float y, t_data *data, int color);
float			normalize_angle(float angle);
int				first_read(char *line, t_data *data);
int				second_read(char *line, t_data *data);
int				third_read(char *line, t_data *data, int v, int a);
int				zero_read(char *line, t_data *data, int v, int a);
int				get_reso(char *line, int v);
int				read_r(char *line, t_data *data);
void			go_read(t_data *data);
void			read_map1(char *line, int a, t_data *data);
void			read_map(t_data *data, int *a);
int				read_s(char *line, t_data *data);
int				read_no(char *line, t_data *data);
int				read_so(char *line, t_data *data);
int				read_ea(char *line, t_data *data);
int				read_we(char *line, t_data *data);
int				read_f(char *line, t_data *data);
int				get_floor(char *line, t_data *data, int v);
int				get_floor2(char *line, t_data *data, int v);
int				get_floor3(char *line, t_data *data, int v);
int				check_path(char *line, char *print);
int				read_c(char *line, t_data *data);
int				get_ceil(char *line, t_data *data, int v);
int				get_ceil2(char *line, t_data *data, int v);
int				get_ceil3(char *line, t_data *data, int v);
void			render3dwall(t_data *data, int id, float angle);
void			rect(int x, int y, int width, t_data *data);
void			rect1(int x, int y, int width, t_data *data);
void			rect2(int x, int y, int width, t_data *data);
void			rect_txt(t_data *data);
void			init_spt(t_data *data);
void			to_sprite(t_spt *sprite, t_player *player, t_data *data, int m);
void			draw_sprite1(t_data *data, float x_off, float y_off, int id);
void			sprite_sort(t_spt *spt1, t_spt *spt2);
void			to_sort(t_spt *spt);
void			bc(t_data *data);
void			draw_ray(t_data *data, t_ray *ray);
void			to_ray(float angle, t_data *data, float max);
void			ray_cast_v(int id, t_data *data, float angle, t_ray *ray);
void			ray_cast_h(int id, t_data *data, float angle, t_ray *ray);
void			init(t_data *data);
void			my_player(t_data *data, int e);
int				rgb_to_int(int r, int g, int b);
void			draw_player(t_data *data);
void			update(t_data *data);
void			draw_view(t_data *data);
void			draw_box(t_data *data, int x, int y, int color);
void			draw_map(t_data *data);
int				checkwall(int x, int y);
int				check_sprite(int x, int y);
int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);
int				destruct(t_data *data);
int				check_rgb(char *s);
int				skip_numbers(char *line);
int				check_rgb(char *s);

#endif
