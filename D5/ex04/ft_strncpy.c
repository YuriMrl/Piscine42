/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <emorlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:13:24 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/21 11:25:39 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;
	int				full;

	i = 0;
	full = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			full = 1;
		if (full == 1)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
