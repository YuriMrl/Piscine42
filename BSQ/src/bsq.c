/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:46:29 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/25 09:46:31 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

t_map	*create_empty_map(t_infos *infos)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (map == 0)
		mem_alloc_error();
	map->sqr.value = 0;
	map->sqr.x = -1;
	map->sqr.y = -1;
	map->tiles = malloc(sizeof(int *) * 2);
	if (map->tiles == 0)
		mem_alloc_error();
	map->infos = infos;
	return (map);
}

t_infos	*get_map_infos(int fd)
{
	t_infos *infos;
	char	row_count[8];
	char	trash;
	int		i;

	if ((infos = malloc(sizeof(t_infos))) == 0)
		mem_alloc_error();
	i = -1;
	while (++i < 7)
	{
		if (read(fd, row_count + i, 1) == -1)
			return (0);
		if (row_count[i] < '0' || row_count[i] > '9')
			break ;
	}
	if (i < 7)
		infos->empty = row_count[i];
	else if (read(fd, &(infos->empty), 1) <= 0)
		return (0);
	row_count[i] = '\0';
	infos->height = ft_atoi(row_count);
	if (read(fd, &(infos->full), 1) == -1 || read(fd, &(infos->square), 1) == -1
		|| read(fd, &trash, 1) <= 0 || trash != '\n')
		return (0);
	return (infos);
}

int		display(int fd, t_map *map)
{
	int		x;
	int		y;
	char	*buffer;

	if (get_map_infos(fd) == 0)
		return (1);
	buffer = malloc(sizeof(char) * (map->infos->width + 1));
	if (buffer == 0)
		mem_alloc_error();
	buffer[map->infos->width] = '\n';
	y = -1;
	while (++y < map->infos->height)
	{
		if (get_line(fd, buffer, map) == 0 && y != map->infos->height - 1)
			return (1);
		x = -1;
		while (++x < map->infos->width)
		{
			if (x <= map->sqr.x && x >= map->sqr.x - map->sqr.value + 1
			&& y <= map->sqr.y && y >= map->sqr.y - map->sqr.value + 1)
				buffer[x] = map->infos->square;
		}
		write(1, buffer, map->infos->width + 1);
	}
	return (0);
}

int		bsq(char *filename)
{
	int		fd;
	t_map	*map;
	t_infos	*infos;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	infos = get_map_infos(fd);
	if (infos == 0)
		return (1);
	map = create_empty_map(infos);
	if (get_sqr(fd, map))
		return (1);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1 || display(fd, map))
		return (1);
	close(fd);
	return (0);
}
