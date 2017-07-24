/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <emorlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:28:33 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/24 10:57:52 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	str = ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
			&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			&& !(str[i - 1] >= '0' && str[i - 1] <= '9'))
			str[i] -= 32;
		i++;
	}
	return (str);
}
