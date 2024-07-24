/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:33:54 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/24 18:53:15 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ordered(t_stack_node *stack)
{
	if (stack == NULL || stack->fwd == NULL)
		return (true);
	if (stack->value > stack->fwd->value)
		return (false);
	return (ordered(stack->fwd));
}

t_stack_node	*find_min_price_node(t_stack_node *head)
{
	t_stack_node	*min_node;
	long			min_price;

	min_node = NULL;
	min_price = LONG_MAX;
	while (head != NULL)
	{
		if (head->push_price < min_price)
		{
			min_price = head->push_price;
			min_node = head;
		}
		head = head->fwd;
	}
	return (min_node);
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
