/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:35 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/21 15:36:13 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	populate_array(t_stack_node *head, int *values, int size)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = head;
	while (i < size)
	{
		values[i] = current->value;
		current = current->fwd;
		i++;
	}
}

void	insertion_sort(int *values, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = key;
		i++;
	}
}

void	p(t_stack_node **a, t_stack_node **b, int median, int *count_a)
{
	int	size;
	int	i;

	size = *count_a;
	*count_a = 0;
	while (size-- > 0)
	{
		if ((*a)->value < median)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
			(*count_a)++;
		}
	}
	i = 0;
	while (i < *count_a)
	{
		rra(a);
		i++;
	}
}
