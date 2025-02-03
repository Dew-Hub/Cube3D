/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:53 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:54 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05

# define EVENT_KEY_PRESS 2
# define KEY_RELEASE_EVENT 3
# define WINDOW_CLOSE 17

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

# include <stdlib.h>

typedef struct s_xpm_image_files
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_count;
	int		south_count;
	int		west_count;
	int		east_count;
}			t_xpm_image_files;

typedef struct s_color_data
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		count;
	int		red;
	int		green;
	int		blue;
}			t_color_data;

typedef struct s_map_data
{
	char	**text;
	int		starting_line;
	int		row_count;
	int		col_count;

	int		player_count;
	int		player_row;
	int		player_col;
}			t_map_data;

typedef struct s_game_config
{
	int					argument_count;
	char				*filename;

	char				**text;
	int					total_line_count;
	int					full_line_count;
	int					empty_line_count;

	t_xpm_image_files	*xpm_files;
	t_color_data		*floor_color;
	t_color_data		*ceiling_color;
	t_map_data			*map;
}			t_game_config;

typedef struct s_vector2d
{
	double	x;
	double	y;
}			t_vector2d;

typedef struct s_integer_vector
{
	int	x;
	int	y;
}		t_integer_vector;

typedef struct s_player_state
{
	t_vector2d	position;
	t_vector2d	direction;
	t_vector2d	camera_plane;
}				t_playe_state;

typedef struct s_key_bindings
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_key_bindings;

typedef struct s_mlx_image_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_image_data;

typedef struct s_game_state
{
	void				*mlx;
	void				*window;
	t_mlx_image_data	*screen;
	t_mlx_image_data	*north_image;
	t_mlx_image_data	*south_image;
	t_mlx_image_data	*west_image;
	t_mlx_image_data	*east_image;
	int					floor_rgb;
	int					ceiling_rgb;
	t_key_bindings		keys;
	t_playe_state		*player;
}				t_game_state;

typedef struct s_c3d
{
	t_game_config		*config;
	t_game_state		*game;
}				t_c3d;

typedef struct s_screen_info
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen_info;

typedef struct s_raycaster
{
	t_integer_vector	map_position;
	t_vector2d			real_position;
	t_vector2d			direction;
	t_vector2d			side_dist;
	t_vector2d			next_hit_dist;
	t_integer_vector	map_step;
	int					hit_wall;
	char				hit_wall_side;
	double				view_of_wall;
	double				hit_point_wall;
	t_screen_info		screen;
}					t_raycaster;

void	configure_cub3d(t_c3d *cub3d, int argument_count, char *filename);
void	release_cub3d_config(t_c3d *cub3d);
void	initialize_xpm_image_files(t_c3d *cub3d);
void	release_xpm(t_c3d *cub3d);
void	initialize_colors(t_c3d *cub3d);
void	release_colors(t_c3d *cub3d);
void	initialize_map(t_c3d *cub3d);
void	release_map(t_c3d *cub3d);
void	validate_arguments(t_c3d *cub3d);
void	validate_blackhole_config(t_c3d *cub3d);
void	initialize_line_count(t_c3d *cub3d);
void	initialize_config_text(t_c3d *cub3d);
void	initialize_element_count(t_c3d *cub3d);
void	validate_elements(t_c3d *cub3d);
void	verify_xpm_files(t_c3d *cub3d, char *line);
void	validate_floor_color(t_c3d *cub3d, char *line);
void	check_ceiling_color(t_c3d *cub3d, char *line);
void	initialize_map_text(t_c3d *cub3d);
char	**create_equal_row_length_map(t_c3d *cub3d);
void	validate_map_for_empty_lines(t_c3d *cub3d);
void	check_map_characters(t_c3d *cub3d);
void	validate_map_walls(t_c3d *cub3d);
void	validate_map_spaces(t_c3d *cub3d);
void	validate_map(t_c3d *cub3d);
char	*get_next_line(t_c3d *cub3d, int fd);
int		is_line_blank(char *line);

void	initialize_game(t_c3d *cub3d);
void	free_game(t_c3d *cub3d);
void	initialize_mlx(t_c3d *cub3d);
void	release_mlx_resources(t_c3d *cub3d);
void	initialize_game_screen(t_c3d *cub3d);
void	release_screen_resources(t_c3d *cub3d);
void	initialize_north_image(t_c3d *cub3d);
void	initialize_south_image(t_c3d *cub3d);
void	initialize_west_image(t_c3d *cub3d);
void	initialize_east_image(t_c3d *cub3d);
void	setup_ceiling_rgb(t_c3d *cub3d);
void	setup_floor_rgb(t_c3d *cub3d);
void	release_xpm_resources(t_c3d *cub3d);
void	setup_player(t_c3d *cub3d);
void	release_player(t_c3d *cub3d);

void	init_ray_properties(t_raycaster *ray, t_playe_state *player, int x);
void	draw_ray_until_wall(t_raycaster *ray, t_map_data *map);
void	set_wall_properties_with_ray(t_raycaster *ray, t_playe_state *player);
void	set_texture_properties(t_raycaster *ray);
void	fill_screen_with_rays(t_raycaster *ray, t_game_state *game, int x);
void	execute_raycasting(t_c3d *cub3d);

void	move_player_up(t_map_data *map, t_playe_state *player);
void	move_player_down(t_map_data *map, t_playe_state *player);
void	move_player_left(t_map_data *map, t_playe_state *player);
void	move_player_right(t_map_data *map, t_playe_state *player);
void	rotate_player_left(t_playe_state *player);
void	rotate_player_right(t_playe_state *player);

size_t	get_image_color(t_mlx_image_data *image, int x, int y);
void	put_pixel_to_mlx_image(t_mlx_image_data *image, int x,
			int y, int color);
int		handle_window_close(t_c3d *cub3d);
int		handle_key_press(int key, t_c3d *cub3d);
int		handle_key_release(int key, t_c3d *cub3d);
int		process_game_loop(t_c3d *cub3d);

t_c3d	*initialize_c3d(int argument_count, char *filename);
void	free_cub3d(t_c3d *cub3d);
void	report_error(t_c3d *cub3d, char *message);

#endif