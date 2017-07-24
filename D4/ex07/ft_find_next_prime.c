/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:00:35 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/18 15:24:36 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb <= 0)
		return (0);
	i = 2;
	while (nb % i != 0 && nb != i)
		i++;
	if (nb % i == 0 && nb != i)
		return (0);
	else
		return (1);
}

int		ft_find_next_prime(int nb)
{
	return (ft_is_prime(nb) == 1 ? nb : ft_find_next_prime(nb + 1));
}
