/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <emorlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:21:15 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/20 15:23:46 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strncat(char *dest, char *src, int nb)
{
	int lendest;
	int i;

	lendest = ft_strlen(dest);
	i = 0;
	while (src[i] && i < nb)
	{
		dest[lendest] = src[i];
		lendest++;
		i++;
	}
	dest[lendest] = '\0';
	return (dest);
}
