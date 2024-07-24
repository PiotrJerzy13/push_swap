/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:00:17 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/24 19:00:25 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_stack(t_stack_node *stack)
{
	int				median;
	int				i;
	int				length;
	t_stack_node	*current;

	if (!stack)
		return ;
	length = stack_length(stack);
	median = length / 2;
	i = 0;
	current = stack;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->fwd;
		i++;
	}
}

int	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	split_error_exit(t_stack_node **a, char **split)
{
	if (a)
		release_stack(a);
	if (split)
		free_array(split);
	write(2, "Error: Invalid input\n", 21);
	exit(1);
}
