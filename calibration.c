/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:32:28 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 13:32:35 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_price(t_stack_node *node, int len)
{
	if (node->median)
		return (node->place);
	else
		return (len - node->place);
}

void	reset_cheapest_flags(t_stack_node *b)
{
	while (b != NULL)
	{
		b->target = false;
		b = b->fwd;
	}
}

t_stack_node	*find_cheapest_node(t_stack_node *b)
{
	t_stack_node	*cheapest_node;
	long			best_match_value;

	cheapest_node = NULL;
	best_match_value = LONG_MAX;
	while (b != NULL)
	{
		if (b->price < best_match_value)
		{
			best_match_value = b->price;
			cheapest_node = b;
		}
		b = b->fwd;
	}
	return (cheapest_node);
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_node = find_min_price_node(b);
	if (cheapest_node != NULL)
		cheapest_node->target = true;
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
