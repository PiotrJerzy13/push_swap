/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:37:39 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 17:57:55 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_nondigit(char *str)
{
	int	idx;

	idx = 0;
	if ((str[idx] == '+' || str[idx] == '-')
		&& !(str[idx + 1] >= '0' && str[idx + 1] <= '9'))
		return (1);
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	if (str[idx] == '0' && str[idx + 1] != '\0' && str[idx + 1] != ' ')
		return (1);
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (1);
		idx++;
	}
	return (0);
}

void	release_stack(t_stack_node **stack_ptr)
{
	t_stack_node	*node_ptr;
	t_stack_node	*temp_node;

	if (!stack_ptr || !*stack_ptr)
		return ;
	node_ptr = *stack_ptr;
	while (node_ptr)
	{
		temp_node = node_ptr->fwd;
		free(node_ptr);
		node_ptr = temp_node;
	}
	*stack_ptr = NULL;
}

int	has_duplicate_value(t_stack_node *stack, long num)
{
	t_stack_node	*node_ptr;

	node_ptr = stack;
	while (node_ptr)
	{
		if (node_ptr->value == num)
			return (1);
		node_ptr = node_ptr->fwd;
	}
	return (0);
}

bool	validate_input(t_stack_node **stack, char *arg, long num)
{
	if (has_nondigit(arg))
		return (false);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	if (has_duplicate_value(*stack, num))
		return (false);
	return (true);
}

bool	handle_errors(t_stack_node **stack, char *arg_array, long n)
{
	if (!validate_input(stack, arg_array, n))
	{
		return (false);
	}
	return (true);
}
