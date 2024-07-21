/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:07:21 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 20:03:07 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_opt_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*target_node;

	cheapest = return_cheapest(*b);
	target_node = cheapest->target_node;
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b);
		else
			rrb(b);
	}
	while (*a != target_node)
	{
		if (target_node->above_median)
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
			if (current_a->value > b->value)
			{
				if (!target_node || current_a->value < target_node->value)
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

void	transfer_optimal_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rr(a, b);
		choose_stack(*a);
		choose_stack(*b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
	{
		while (*a != cheapest->target_node && *b != cheapest)
			rrr(a, b);
		choose_stack(*a);
		choose_stack(*b);
	}
	move_ready(b, cheapest, 'b');
	move_ready(a, cheapest->target_node, 'a');
	pa(a, b);
}
