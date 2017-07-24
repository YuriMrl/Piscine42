/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <emorlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:11:17 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/24 10:53:59 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (!(str[count] == '\0'))
	{
		count++;
	}
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int len;

	len = ft_strlen(to_find);
	i = 0;
	j = 0;
	if (len == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
		{
			if (j == len - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
