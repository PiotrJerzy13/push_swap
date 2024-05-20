/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 23:03:24 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	find_median(t_stack_node *head, int size)
{
	int				*values;
	t_stack_node	*current;
	int				median;
	int				i;
	int				j;
	int				key;

	values = malloc(sizeof(int) * size);
	current = head;
	i = 0;
	while (i < size)
	{
		values[i] = current->value;
		current = current->fwd;
		i++;
	}
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
	median = values[size / 2];
	free(values);
	return (median);
}

void	quick_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	median;
	int	count_a ;
	int	total;
	int	i;
	int	count_b;

	if (size < 2)
		return ;
	median = find_median(*a, size);
	count_a = 0;
	total = size;
	i = 0;
	while (size-- > 0)
	{
		if ((*a)->value < median)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
			count_a++;
		}
	}
	while (i < count_a)
	{
		rra(a);
		i++;
	}
	quick_sort(a, b, count_a);
	count_b = total - count_a;
	while (count_b-- > 0)
	{
		pa(a, b);
	}
	quick_sort(a, b, total - count_a);
}

int	initialize_stack(t_stack_node **a, char *input)
{
	char			**values;
	t_stack_node	*new_node;
	t_stack_node	*last;
	int				i;
	int				val;

	values = ft_split(input, ' ');
	if (values == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (values[i])
	{
		val = atoi(values[i]);
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
		{
			*a = new_node;
		}
		else
		{
			last = *a;
			while (last->fwd)
				last = last->fwd;
			last->fwd = new_node;
			new_node->bwd = last;
		}
		i++;
	}
	free_array(values);
	return (1);
}

void	print_stack(t_stack_node *a)
{
	t_stack_node	*current;

	current = a;
	printf("Sorted values: ");
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
	if (argc < 2)
		return (1);
	if (!initialize_stack(&a, argv[1]))
		return (1);
	len = stack_length(a);
	if (len == 3)
	{
		sort_three(&a);
	}
	else if (len == 5)
	{
		sort_five(&a, &b);
	}
	else
		quick_sort(&a, &b, len);
	print_stack(a);
	free_stack(&a);
	return (0);
}
