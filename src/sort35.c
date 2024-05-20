/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort35.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:37:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/20 14:37:46 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_stack_node	*return_biggest(t_stack_node *stack)
{
	int				biggest_value;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_value = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest_value)
		{
			biggest_node = stack;
			biggest_value = stack->value;
		}
		stack = stack->fwd;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = return_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->fwd == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->fwd->value)
		sa(a);
}
static t_stack_node *find_min(t_stack_node *stack) {
    t_stack_node *min_node = stack;
    t_stack_node *current = stack;
    while (current) {
        if (current->value < min_node->value) {
            min_node = current;
        }
        current = current->fwd;
    }
    return min_node;
}

// Function to sort a stack with 5 nodes
void sort_five(t_stack_node **a, t_stack_node **b) {
    // Move the two smallest elements to stack B
    for (int i = 0; i < 2; i++) {
        t_stack_node *min_node = find_min(*a);
        while ((*a)->value != min_node->value) {
            if (min_node == (*a)->fwd || min_node == (*a)->fwd->fwd) {
                ra(a);
            } else {
                rra(a);
            }
        }
        pb(a, b);
    }

    // Sort the remaining three elements in stack A
    sort_three(a);

    // Move the elements back from stack B to stack A
    pa(a, b);
    pa(a, b);
}

int find_median(t_stack_node *head, int size)
{
    int *values = malloc(sizeof(int) * size);
    t_stack_node *current = head;

    // Fill the values array
    for (int i = 0; i < size; i++) {
        values[i] = current->value;
        current = current->fwd;
    }

    // Sort the array
    for (int i = 1; i < size; i++) {
        int key = values[i];
        int j = i - 1;
        while (j >= 0 && values[j] > key) {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = key;
    }
    int median = values[size / 2];
    free(values);
    return median;
}