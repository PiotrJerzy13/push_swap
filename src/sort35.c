/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort35.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:37:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/21 15:36:17 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*return_biggest(t_stack_node *stack)
{
	int				biggest_value;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_value = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest_value)
		{
			biggest_node = stack;
			biggest_value = stack->value;
		}
		stack = stack->fwd;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = return_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->fwd == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->fwd->value)
		sa(a);
}

static t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;

	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->value < min_node->value)
		{
			min_node = current;
		}
		current = current->fwd;
	}
	return (min_node);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	int				i;

	i = 0;
	while (i < 2)
	{
		min_node = find_min(*a);
		while ((*a)->value != min_node->value)
		{
			if (min_node == (*a)->fwd || min_node == (*a)->fwd->fwd)
			{
				ra(a);
			}
			else
			{
				rra(a);
			}
		}
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
