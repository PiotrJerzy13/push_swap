/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/24 17:22:00 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	leaks()
// {
// 	system("leaks push_swap");
// }

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	long			match;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	target_node = NULL;
	while (b)
	{
		match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < match)
			{
				match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->fwd;
		}
		if (match == INT_MAX)
			target_node = return_smallest(a);
		b->target_node = target_node;
		b = b->fwd;
	}
}

int	process_values(t_stack_node **a, char **values, int i)
{
	t_stack_node	*new_node;
	long			val;

	while (values[i])
	{
		val = ft_atol(values[i]);
		if (!handle_errors(a, values[i], val))
		{
			free_errors(a, values, i);
			return (0);
		}
		new_node = create_node(val);
		if (!new_node)
		{
			free_errors(a, values, i);
			return (0);
		}
		if (!(*a))
			*a = new_node;
		else
			append_node(a, new_node);
		i++;
	}
	return (1);
}

int	initialize_stack_single(t_stack_node **a, char *input)
{
	char	**values;
	int		result;

	values = ft_split(input, ' ');
	if (values == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	result = process_values(a, values, 0);
	free_array(values);
	return (result);
}

int	initialize_stack(t_stack_node **a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!initialize_stack_single(a, argv[1]))
			return (0);
	}
	else
	{
		if (!init_stack_no_split(a, argc, argv))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (!initialize_stack(&a, argc, argv))
		return (1);
	if (stack_ordered(a))
	{
		free_stack(&a);
		return (0);
	}
	len = stack_length(a);
	if (len == 3)
		sort_three(&a);
	else
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
