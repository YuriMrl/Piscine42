/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:51:19 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/26 07:12:13 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		compute_value(int x, char ground, t_map *map)
{
	int min_value;

	if (ground == map->infos->full)
		return (0);
	if (x == 0)
		return (1);
	min_value = map->tiles[1][x - 1];
	if (min_value > map->tiles[0][x])
		min_value = map->tiles[0][x];
	if (min_value > map->tiles[0][x - 1])
		min_value = map->tiles[0][x - 1];
	return (min_value + 1);
}

int		compute_line(char *line, int y, t_map *map)
{
	int x;
	int *temp;

	x = 0;
	while (x < map->infos->width)
	{
		if (line[x] != map->infos->full && line[x] != map->infos->empty)
			return (1);
		map->tiles[1][x] = compute_value(x, line[x], map);
		if (map->tiles[1][x] > map->sqr.value)
		{
			map->sqr.value = map->tiles[1][x];
			map->sqr.x = x;
			map->sqr.y = y;
		}
		x++;
	}
	temp = map->tiles[0];
	map->tiles[0] = map->tiles[1];
	map->tiles[1] = temp;
	return (0);
}

void	create_empty_tiles(t_map *map)
{
	map->tiles[0] = malloc(sizeof(int) * map->infos->width);
	map->tiles[1] = malloc(sizeof(int) * map->infos->width);
	if (map->tiles[0] == 0 || map->tiles[1] == 0)
		mem_alloc_error();
	fill(map->tiles[0], map->infos->width, 0);
}

int		get_sqr(int fd, t_map *map)
{
	char	*buffer;
	int		line_nbr;

	line_nbr = 0;
	map->infos->width = get_first_line(fd, &buffer);
	if (map->infos->width <= 0)
		return (1);
	create_empty_tiles(map);
	if (compute_line(buffer, line_nbr++, map))
		return (1);
	free(buffer);
	buffer = malloc(sizeof(char) * map->infos->width);
	if (buffer == 0)
		mem_alloc_error();
	while (line_nbr < map->infos->height)
	{
		if ((get_line(fd, buffer, map) != map->infos->width
		&& line_nbr != map->infos->height - 1)
		|| compute_line(buffer, line_nbr, map))
			return (1);
		line_nbr++;
	}
	free(buffer);
	return (0);
}
