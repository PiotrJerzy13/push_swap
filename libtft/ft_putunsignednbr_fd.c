/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:37:16 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 22:10:55 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtft.h"

int	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = count + ft_putunsignednbr_fd(n / 10, fd);
	}
	count = count + ft_putchar_fd('0' + (n % 10), fd);
	return (count);
}
