/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheuril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:36:29 by btheuril          #+#    #+#             */
/*   Updated: 2017/07/25 19:36:30 by btheuril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	mem_alloc_error(void)
{
	write(2, MEM_ALLOC_ERROR, sizeof(MEM_ALLOC_ERROR) - 1);
	exit(1);
}
