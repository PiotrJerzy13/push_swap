/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:49:10 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 20:15:48 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	error_nondigit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-')
		&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->fwd;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_duplicated(t_stack_node *a, long n)
{
	t_stack_node	*current;

	current = a;
	while (current)
	{
		if (current->value == n)
			return (1);
		current = current->fwd;
	}
	return (0);
}

bool	handle_errors(t_stack_node **a, char *argv, long n)
{
	if (error_nondigit(argv))
		return (false);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	if (error_duplicated(*a, n))
		return (false);
	return (true);
}

void	free_errors(t_stack_node **a, char **argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}
