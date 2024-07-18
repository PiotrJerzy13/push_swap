/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:11:55 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/18 17:18:59 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*return_biggest(t_stack_node *stack)
{
	int				biggest_value;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_value = INT_MIN;
	while (stack)
	{
		if (stack->node > biggest_value)
		{
			biggest_node = stack;
			biggest_value = stack->node;
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
	if ((*a)->node > (*a)->fwd->node)
		sa(a);
}

t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest)
{
	if (!stack)
		return (smallest);
	if (stack->node < smallest->node)
		smallest = stack;
	return (find_smallest(stack->fwd, smallest));
}

t_stack_node	*return_smallest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	return (find_smallest(stack, stack));
}

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->node = value;
	new_node->fwd = NULL;
	new_node->bwd = NULL;
	return (new_node);
}
