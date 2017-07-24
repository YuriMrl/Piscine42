/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 11:53:45 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/07 12:56:45 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = 0;
	while (nb1 <= 98)
	{
		nb2 = nb1 + 1;
		while (nb2 <= 99)
		{
			ft_putchar(nb1 / 10 + 48);
			ft_putchar(nb1 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(nb2 / 10 + 48);
			ft_putchar(nb2 % 10 + 48);
			if (!((nb1 == 98) & (nb2 == 99)))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			nb2++;
		}
		nb1++;
	}
}
