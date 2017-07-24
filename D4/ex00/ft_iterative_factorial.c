/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:44:12 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/18 15:21:36 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	if ((nb > 12) || (nb < 0))
		return (0);
	result = 1;
	if (nb == 0)
		return (1);
	while (nb > 0)
		result *= nb--;
	return (result);
}
