/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:05:49 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/24 11:20:53 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(a);
	len_b = stack_length(b);
	while (b)
	{
		if (b->above_median)
			b->push_price = b->index;
		else
			b->push_price = len_b - (b->index);
		if (b && b->target_node && b->target_node->above_median)
			b->push_price += b->target_node->index;
		else if (b && b->target_node && !b->target_node->above_median)
			b->push_price += len_a - (b->target_node->index);
		b = b->fwd;
	}
}

static void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_match_node;
	long			best_match_value;

	if (!b)
		return ;
	best_match_value = INT_MAX;
	while (b != NULL)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->fwd;
	}
	best_match_node->cheapest = true;
}

void	calibrate_nodes(t_stack_node *a, t_stack_node *b)
{
	choose_stack(a);
	choose_stack(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

static void	transfer_optimal_node(t_stack_node **a, t_stack_node **b)
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
	push_r(b, cheapest, 'b');
	push_r(a, cheapest->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest;

	len_a = stack_length(*a);
	while (len_a-- > 3)
		pb(a, b);
	sort_three(a);
	while (*b != NULL)
	{
		calibrate_nodes(*a, *b);
		transfer_optimal_node(a, b);
	}
	choose_stack(*a);
	smallest = return_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
