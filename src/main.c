/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 17:17:31 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	quick_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	median;
	int	count_a;
	int	count_b;
	int	total;
	int	i;

	i = 0;
	if (size < 2)
		return ;
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	if (size == 5)
	{
		sort_five(a, b);
		return ;
	}
	median = find_median(*a, size);
	count_a = 0;
	total = size;
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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				len;
	int 			val;
	int 			i;
	char			**values;

	i = 0;
	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	values = ft_split(argv[1], ' ');
	if (values == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (values[i])
	{
		val = atoi(values[i]);
		if (!handle_errors(&a, values[i], val))
		{
			free_errors(&a, values, argc);
		}
		new_node = create_node(val);
		if (!a)
			a = new_node;
		else
		{
			new_node->bwd = b;
			b->fwd = new_node;
		}
		b = new_node;
		i++;
	}
	free_array(values);
	len = stack_length(a);
	quick_sort(&a, &b, len);
	printf("Sorted values: ");
	current = a;
	while (current)
	{
		printf("%d ", current->value);
		current = current->fwd;
	}
	printf("\n");
	free_stack(&a);
	return (0);
}
