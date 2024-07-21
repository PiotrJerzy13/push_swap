/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:07:21 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 13:07:38 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack_a(t_stack_node **a, t_stack_node *target_node)
{
	while (*a != target_node)
	{
		if (target_node->median)
			ra(a);
		else
			rra(a);
	}
}

void	align_stack_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->median)
			rb(b);
		else
			rrb(b);
	}
}

void	align(t_stack_node **a, t_stack_node **b, t_nodes *nodes)
{
	if (nodes->cheap->median && nodes->node->median)
	{
		while (*a != nodes->node && *b != nodes->cheap)
			rr(a, b);
	}
	else if (!nodes->cheap->median && !nodes->node->median)
	{
		while (*a != nodes->node && *b != nodes->cheap)
			rrr(a, b);
	}
}

void	move_opt_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*target_node;

	cheapest = return_cheapest(*b);
	target_node = cheapest->target_node;
	while (*b != cheapest)
	{
		if (cheapest->median)
			rb(b);
		else
			rrb(b);
	}
	while (*a != target_node)
	{
		if (target_node->median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*smallest_node;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	smallest_node = return_smallest(a);
	while (b)
	{
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->node > b->node)
			{
				if (!target_node || current_a->node < target_node->node)
				{
					target_node = current_a;
				}
			}
			current_a = current_a->fwd;
		}
		if (!target_node)
			target_node = smallest_node;
		b->target_node = target_node;
		b = b->fwd;
	}
}
