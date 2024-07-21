/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:33:54 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 19:46:48 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*number_to_push;

	if (!src || !*src)
		return ;
	number_to_push = *src;
	*src = number_to_push->fwd;
	if (*src)
		(*src)->bwd = NULL;
	number_to_push->fwd = *dst;
	if (*dst)
		(*dst)->bwd = number_to_push;
	*dst = number_to_push;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_stack(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_stack(b, a);
	write(1, "pb\n", 3);
}

bool	ordered(t_stack_node *stack)
{
	if (stack == NULL || stack->fwd == NULL)
		return (true);
	if (stack->value > stack->fwd->value)
		return (false);
	return (ordered(stack->fwd));
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;

	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest_node = stack;
			break ;
		}
		stack = stack->fwd;
	}
	return (cheapest_node);
}
