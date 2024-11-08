/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:38:13 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 22:12:20 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	size_t	nb;
	char	*p;

	nb = n * size;
	p = malloc(nb);
	if (p != NULL)
	{
		i = 0;
		while (i < nb)
		{
			p[i] = 0;
			i++;
		}
	}
	return (p);
}
