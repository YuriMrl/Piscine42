/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <emorlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:23:07 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/21 11:56:30 by emorlier         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int lendest;
	int i;

	lendest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[lendest] = src[i];
		lendest++;
		i++;
	}
	dest[lendest] = '\0';
	return (dest);
}
