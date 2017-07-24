/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:10:06 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/20 09:51:51 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int isneg;
	int nb;

	isneg = 0;
	nb = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == '\f') || (str[i] == ' ') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		isneg = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (isneg == 1)
		return (-nb);
	else
		return (nb);
}
