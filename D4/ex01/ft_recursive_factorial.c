/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:54:19 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/18 18:16:07 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	if ((nb > 12) || (nb < 0))
		return (0);
	result = 1;
	if (nb > 0)
		result *= ft_recursive_factorial(nb - 1);
	if (nb > 1)
		return (result * nb);
	else
		return (result);
	return (0);
}
