/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:07:21 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/22 12:21:20 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_opt_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*target_node;

	cheapest = return_cheapest(*b);
	target_node = cheapest->target;
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
	t_stack_node	*node_a;
	t_stack_node	*target_node;

	smallest_node = return_smallest(a);
	while (b)
	{
		target_node = NULL;
		node_a = a;
		while (node_a)
		{
			if (node_a->value > b->value)
			{
				if (!target_node || node_a->value < target_node->value)
				{
					target_node = node_a;
				}
			}
			node_a = node_a->fwd;
		}
		if (!target_node)
			target_node = smallest_node;
		b->target = target_node;
		b = b->fwd;
	}
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_node = find_min_price_node(b);
	if (cheapest_node != NULL)
		cheapest_node->cheapest = true;
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*current;

	len_a = stack_length(a);
	len_b = stack_length(b);
	current = b;
	while (current != NULL)
	{
		calculate_price_node(current, len_a, len_b);
		current = current->fwd;
	}
}
