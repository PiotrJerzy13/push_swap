/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:19:56 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/11/05 19:37:27 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_price_node(t_stack_node *node, int len_a, int len_b)
{
	int	price;

	if (!node)
		return ;
	price = 0;
	if (node->above_median)
		price = node->index;
	else
		price = len_b - node->index;
	if (node->target->above_median)
		price += node->target->index;
	else
		price += len_a - node->target->index;
	node->push_price = price;
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
	int		i;

	values = ft_split(input, ' ');
	if (values == NULL)
	{
		split_error_exit(a, values);
		return (0);
	}
	i = 0;
	while (values[i])
	{
		if (!is_number(values[i]))
		{
			split_error_exit(a, values);
			return (0);
		}
		i++;
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

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->fwd;
	}
	printf("\n");
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
	if (ordered(a))
	{
		release_stack(&a);
		return (0);
	}
	len = stack_length(a);
	if (len == 3)
		sort_three(&a);
	else
		push_swap(&a, &b);
	printf("The stack has been sorted successfully.\nSorted stack: ");
	print_stack(a);
	release_stack(&a);
	release_stack(&b);
	return (0);
}
