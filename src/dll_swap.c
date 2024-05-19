/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:17:36 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/23 18:00:52 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	dll_swap(t_stack_node **current)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *current;
	second = first->fwd;
	if (!first || !second)
		return (0);
	if (second->fwd)
		second->fwd->bwd = first;
	if (first->bwd)
		first->bwd->fwd = second;
	first->fwd = second->fwd;
	second->bwd = first->bwd;
	second->fwd = first;
	first->bwd = second;
	*current = second;
	return (1);
}
