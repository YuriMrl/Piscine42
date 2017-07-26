/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:46:18 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/26 10:08:08 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	int end;

	end = 0;
	i = 0;
	while (end == 0)
	{
		if (src[i] == '\0')
			end = 1;
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
 
int		tmp_file(char *filename)
{
	int		fd;
	int		i;

	ft_strcpy(filename, TMP_FILE_PREFIX);
	i = sizeof(TMP_FILE_PREFIX) - 1;
	while ((fd = open(filename, O_WRONLY | O_CREAT | O_EXCL,
								S_IRUSR | S_IWUSR)) == -1)
	{
		if (filename[i] == '\0')
			filename[i] = 'a';
		else if (filename[i] == 'z')
		{
			if (i == MAX_FILENAME_SIZE - 1)
				return (-1);
			filename[++i] = 'a';
			filename[i + 1] = '\0';
		}
		else
			filename[i]++;
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	int		map_file;
	char	buffer[BUFF_SIZE];
	char	filename[MAX_FILENAME_SIZE];
	int		count;

	if (argc == 1)
	{
		map_file = tmp_file(filename);
		while ((count = read(0, buffer, BUFF_SIZE)) > 0)
			write(map_file, buffer, count);
		if (count == -1)
			return (1);
		close(map_file);
		if (bsq(filename))
		{
			write(2, MAP_ERROR, sizeof(MAP_ERROR) - 1);
			write(1, "\n", 1);
		}
	}
	else
		while (argc-- > 1)
		{
			if (bsq(*(++argv)))
				write(2, MAP_ERROR, sizeof(MAP_ERROR) - 1);
			if (argc != 1)
				write(1, "\n", 1);
		}
}
