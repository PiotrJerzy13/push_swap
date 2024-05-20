/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:43 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 15:18:57 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	new_node->value = value;
	new_node->fwd = NULL;
	new_node->bwd = NULL;
	return (new_node);
}

int	stack_length(t_stack_node *head)
{
	int				length;
	t_stack_node	*current;

	current = head;
	length = 0;
	while (current != NULL)
	{
		length++;
		current = current->fwd;
	}
	return (length);
}

int	dll_swap(t_stack_node **current)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *current;
	second = first->fwd;
	if (!first || !second)
		return (0);
	if (second->fwd)
		second->fwd->bwd = first;
	if (first->bwd)
		first->bwd->fwd = second;
	first->fwd = second->fwd;
	second->bwd = first->bwd;
	second->fwd = first;
	first->bwd = second;
	*current = second;
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	stack_ordered(t_stack_node *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->fwd)
	{
		if (stack->value > stack->fwd->value)
			return (false);
		stack = stack->fwd;
	}
	return (true);
}
