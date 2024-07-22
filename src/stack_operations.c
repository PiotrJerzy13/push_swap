/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:40:07 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/23 14:38:24 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_r(t_stack_node **stack, t_stack_node *cheap, char st_na)
{
	while (cheap && *stack != cheap)
	{
		if (st_na == 'a')
		{
			if (cheap && cheap->above_median)
				ra(stack);
			else if (cheap && !cheap->above_median)
				rra(stack);
		}
		else if (st_na == 'b')
		{
			if (cheap && cheap->above_median)
				rb(stack);
			else if (cheap && !cheap->above_median)
				rrb(stack);
		}
	}
}

static void	rotate(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->fwd)
		return ;
	first = *head;
	second = (*head)->fwd;
	*head = second;
	second->bwd = NULL;
	while (second->fwd)
		second = second->fwd;
	second->fwd = first;
	first->bwd = second;
	first->fwd = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
