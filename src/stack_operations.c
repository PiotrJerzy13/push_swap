/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:40:07 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 15:54:22 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	sa(t_stack_node **head)
{
	if (!*head || !(*head)->fwd)
		return ;
	dll_swap(head);
	printf("sa\n");
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_b;

	first_b = *b;
	if (!*b)
		return ;
	*b = (*b)->fwd;
	if (*b)
		(*b)->bwd = NULL;
	first_b->fwd = *a;
	if (*a)
		(*a)->bwd = first_b;
	*a = first_b;
	printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_a;

	first_a = *a;
	if (!*a)
		return ;
	*a = (*a)->fwd;
	if (*a)
		(*a)->bwd = NULL;
	first_a->fwd = *b;
	if (*b)
		(*b)->bwd = first_a;
	*b = first_a;
	printf("pb\n");
}

void	ra(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *head;
	second = first->fwd;
	if (!*head || !(*head)->fwd)
		return ;
	while (second->fwd)
		second = second->fwd;
	*head = first->fwd;
	(*head)->bwd = NULL;
	second->fwd = first;
	first->fwd = NULL;
	first->bwd = second;
	printf("ra\n");
}

void	rra(t_stack_node **head)
{
	t_stack_node	*last;

	last = *head;
	if (! *head || !(*head)->fwd)
		return ;
	while (last->fwd)
		last = last->fwd;
	last->bwd->fwd = NULL;
	last->fwd = *head;
	last->bwd = NULL;
	(*head)->bwd = last;
	*head = last;
	printf("rra\n");
}
