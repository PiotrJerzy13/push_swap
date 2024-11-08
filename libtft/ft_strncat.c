/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:19:30 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 22:10:11 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtft.h"

char	*ft_strlnc(char *dest, const char *src, size_t size)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest && size > 0)
	{
		dest++;
		size--;
	}
	while (*src && size > 1)
	{
		*dest = *src;
		src++;
		dest++;
		size--;
	}
	if (size > 0)
	{
		*dest = '\0';
	}
	return (original_dest);
}
