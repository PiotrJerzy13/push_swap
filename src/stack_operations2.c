/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:35 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/24 19:00:04 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **a, t_stack_node *new_node)
{
	t_stack_node	*last;

	last = *a;
	while (last->fwd)
		last = last->fwd;
	last->fwd = new_node;
	new_node->bwd = last;
}

static void	swap(t_stack_node **head)
{
	t_stack_node	*tmp;

	if (!*head || !(*head)->fwd)
		return ;
	tmp = *head;
	*head = tmp->fwd;
	(*head)->bwd = NULL;
	tmp->fwd = (*head)->fwd;
	tmp->bwd = *head;
	(*head)->fwd = tmp;
	if (tmp->fwd)
		tmp->fwd->bwd = tmp;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

t_stack_node	*return_smallest(t_stack_node *stack)
{
	long			smallest_value;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_value = INT_MAX;
	smallest_node = stack;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_node = stack;
			smallest_value = stack->value;
		}
		stack = stack->fwd;
	}
	return (smallest_node);
}

int	init_stack_no_split(t_stack_node **a, int argc, char **argv)
{
	int				i;
	long			val;
	t_stack_node	*new_node;

	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[i]);
		if (!handle_errors(a, argv[i], val))
		{
			free_errors(a, NULL, argc);
		}
		new_node = create_node(val);
		if (!new_node)
		{
			free_errors(a, NULL, argc);
		}
		if (!(*a))
			*a = new_node;
		else
			append_node(a, new_node);
		i++;
	}
	return (1);
}
