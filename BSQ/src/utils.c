/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:40:22 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/25 12:40:23 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*realloc_str(char **str, int width, int new_width)
{
	char	*new_str;
	char	*old_str;
	int		i;

	i = 0;
	old_str = *str;
	new_str = malloc(sizeof(char) * new_width);
	if (new_str == 0)
		mem_alloc_error();
	while (i < width)
	{
		new_str[i] = old_str[i];
		i++;
	}
	*str = new_str;
	free(old_str);
	return (new_str);
}

void	fill(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
		tab[i++] = value;
}

int		get_first_line(int fd, char **str)
{
	char	*line;
	char	c;
	int		count;
	int		max_size;
	int		read_error;

	max_size = 16;
	if ((line = malloc(sizeof(char) * max_size)) == 0)
		mem_alloc_error();
	count = 0;
	while ((read_error = read(fd, &c, 1)) != 0)
	{
		count++;
		if (count == max_size && (max_size *= 2))
			realloc_str(&line, max_size, max_size * 2);
		else if (read_error == -1)
			return (0);
		if (c == '\n')
			break ;
		line[count - 1] = c;
	}
	*str = line;
	return (count - 1);
}

int		get_line(int fd, char *buffer, t_map *map)
{
	int		len;
	char	trash;
	int		len_trash;

	trash = '\0';
	len = read(fd, buffer, map->infos->width);
	len_trash = read(fd, &trash, 1);
	if (len_trash <= 0 || len <= 0 || trash != '\n')
		return (0);
	return (len);
}

int		ft_atoi(char *str)
{
	long i;
	long negative;
	long nb;

	i = 0;
	negative = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 19) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (int)(negative * nb);
}
