/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:43 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/24 18:55:46 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] && array[i][0] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
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
