/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:20:00 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/14 16:56:17 by pwojnaro         ###   ########.fr       */
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
	int				key;
	int				j;
	int				median;
	int				i;

	i = 0;
	values = malloc(sizeof(int) * size);
	current = head;
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
	if (size < 2) return ;
    int median = find_median(*a, size);
    int countA = 0; // Count elements in stack a that are < median
    int total = size; // Total elements to process

    // Move elements >= median to stack b
    while (size-- > 0) {
        if ((*a)->value < median) {
            pb(a, b);
        } else {
            ra(a);
            countA++;
        }
    }

    // Restore order of stack a
    for (int i = 0; i < countA; i++) {
        rra(a);
    }

    // Recursive call to sort the left half
    quick_sort(a, b, countA);

    // Move elements from stack b back to stack a for sorting
    int countB = total - countA;
    while (countB-- > 0) {
        pa(a, b);
    }

    // Recursive call to sort the right half
    quick_sort(a, b, total - countA);
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

	i = 0;
	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	char **values = ft_split(argv[1], ' ');
	while (values[i])
	{
		val = atoi(values[i]);
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

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
