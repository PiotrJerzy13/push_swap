/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:11:55 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:40 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*return_biggest(t_stack_node *stack)
{
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_node = stack;
	stack = stack->fwd;
	while (stack)
	{
		if (stack->value > biggest_node->value)
		{
			biggest_node = stack;
		}
		stack = stack->fwd;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;
	t_stack_node	*first;
	t_stack_node	*second;

	biggest_node = return_biggest(*a);
	first = *a;
	second = first->fwd;
	if (first == biggest_node)
		ra(a);
	else if (second == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->fwd->value)
		sa(a);
}

t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest)
{
	if (!stack)
		return (smallest);
	if (stack->value < smallest->value)
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
	new_node->value = value;
	new_node->fwd = NULL;
	new_node->bwd = NULL;
	return (new_node);
}
