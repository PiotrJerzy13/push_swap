/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:35 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/20 20:15:34 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	rrb(t_stack_node **head)
{
	t_stack_node	*last;

	last = *head;
	if (!*head || !(*head)->fwd)
		return ;
	while (last->fwd)
		last = last->fwd;
	last->bwd->fwd = NULL;
	last->fwd = *head;
	last->bwd = NULL;
	(*head)->bwd = last;
	*head = last;
	printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}

int	*populate_array(t_stack_node *head, int size)
{
	int				*values;
	int				i;
	t_stack_node	*current;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	current = head;
	i = 0;
	while (i < size)
	{
		values[i] = current->value;
		current = current->fwd;
		i++;
	}
	return (values);
}
