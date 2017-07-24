/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:33:59 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/13 14:12:16 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		size_str;

	i = 0;
	size_str = 0;
	while (str[size_str])
		size_str++;
	size_str = size_str - 1;
	while (i < size_str)
	{
		tmp = str[size_str];
		str[size_str] = str[i];
		str[i] = tmp;
		i++;
		size_str--;
	}
	return (str);
}
