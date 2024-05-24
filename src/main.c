/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/24 17:49:46 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	find_median(t_stack_node *head, int size)
{
	int	median;
	int	*values;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	populate_array(head, values, size);
	insertion_sort(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

void	quick_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	median;
	int	count_a;
	int	count_b;

	if (size < 2)
		return ;
	median = find_median(*a, size);
	count_a = size;
	p(a, b, median, &count_a);
	quick_sort(a, b, count_a);
	count_b = size - count_a;
	while (count_b-- > 0)
	{
		pa(a, b);
	}
	quick_sort(a, b, size - count_a);
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

int	initialize_stack(t_stack_node **a, char *input)
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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (!initialize_stack(&a, argv[1]))
		return (1);
	if (stack_ordered(a))
	{
		free_stack(&a);
		return (0);
	}
	len = stack_length(a);
	if (len == 3)
		sort_three(&a);
	else if (len == 5)
		sort_five(&a, &b);
	else
		quick_sort(&a, &b, len);
	free_stack(&a);
	return (0);
}
