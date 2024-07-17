/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:05:25 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/17 14:07:51 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append(t_stack_node **a, t_stack_node *new_node)
{
	t_stack_node	*last;

	last = *a;
	while (last->fwd)
		last = last->fwd;
	last->fwd = new_node;
	new_node->bwd = last;
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

long	ft_atol(const char *str)
{
	int		pos_sign;
	long	output;

	output = 0;
	pos_sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pos_sign = -1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		output = (output * 10) + (*str - '0');
		str++;
	}
	return (output * pos_sign);
}

void	choose_stack(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->place = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->fwd;
		i++;
	}
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
