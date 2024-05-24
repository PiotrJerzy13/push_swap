/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:08 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/24 11:19:17 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->fwd;
	if (*src)
		(*src)->bwd = NULL;
	node_to_push->bwd = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		(*dst)->fwd = NULL;
	}
	else
	{
		node_to_push->fwd = *dst;
		node_to_push->fwd->bwd = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	choose_stack(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->fwd;
		i++;
	}
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->fwd;
	}
	return (NULL);
}
