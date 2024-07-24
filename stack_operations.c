/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:05:25 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/24 18:47:43 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*number_to_push;

	if (!src || !*src)
		return ;
	number_to_push = *src;
	*src = number_to_push->fwd;
	if (*src)
		(*src)->bwd = NULL;
	number_to_push->fwd = *dst;
	if (*dst)
		(*dst)->bwd = number_to_push;
	*dst = number_to_push;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_stack(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_stack(b, a);
	write(1, "pb\n", 3);
}

void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!head || !*head || !(*head)->fwd)
		return ;
	first = *head;
	second = first->fwd;
	*head = second;
	first->fwd = second->fwd;
	if (second->fwd)
		second->fwd->bwd = first;
	second->fwd = first;
	second->bwd = NULL;
	first->bwd = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
