/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:46:37 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/25 09:46:39 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

# define MAX_FILENAME_SIZE 30
# define BUFF_SIZE 4096
# define MEM_ALLOC_ERROR "Memory allocation error\n"
# define MAP_ERROR "map error"
# define TMP_FILE_PREFIX "/tmp/bsq_a"

typedef struct	s_tile_coords {
	int		x;
	int		y;
	int		value;
}				t_tile_coords;

typedef struct	s_infos {
	int		height;
	int		width;
	char	full;
	char	empty;
	char	square;
}				t_infos;

typedef struct	s_map {
	t_tile_coords	sqr;
	t_infos			*infos;
	int				**tiles;
}				t_map;

int				bsq(char *filename);
char			*realloc_str(char **str, int width, int new_width);
void			fill(int *tab, int size, int value);
int				get_line(int fd, char *buffer, t_map *map);
int				ft_atoi(char *str);
int				get_first_line(int fd, char **str);
int				compute_value(int x, char ground, t_map *map);
int				compute_line(char *line, int y, t_map *map);
int				get_sqr(int fd, t_map *map);
void			mem_alloc_error(void);

#endif
