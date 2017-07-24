/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:17:42 by emorlier          #+#    #+#             */
/*   Updated: 2017/07/11 11:20:27 by emorlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_allnbr(char nbr1, char nbr2, char nbr3)
{
	ft_putchar(nbr1);
	ft_putchar(nbr2);
	ft_putchar(nbr3);
	if (!((nbr1 == '7') & (nbr2 == '8') & (nbr3 == '9')))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char nbr1;
	char nbr2;
	char nbr3;

	nbr1 = '0';
	while (nbr1 <= '9')
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= '9')
		{
			nbr3 = nbr2 + 1;
			while (nbr3 <= '9')
			{
				ft_allnbr(nbr1, nbr2, nbr3);
				nbr3++;
			}
			nbr2++;
		}
		nbr1++;
	}
}
