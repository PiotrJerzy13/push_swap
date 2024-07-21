/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:19:20 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 13:27:23 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotation(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*second_to_last;

	if (!head || !(*head) || !(*head)->fwd)
		return ;
	last = *head;
	while (last->fwd)
	{
		second_to_last = last;
		last = last->fwd;
	}
	if (second_to_last)
		second_to_last->fwd = NULL;
	last->fwd = *head;
	if (*head)
		(*head)->bwd = last;
	last->bwd = NULL;
	*head = last;
}

void	rra(t_stack_node **a)
{
	rev_rotation(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotation(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotation(a);
	rev_rotation(b);
	write(1, "rrr\n", 4);
}

void	move_ready(t_stack_node **stack, t_stack_node *cheap, char st_na)
{
	int	is_median;

	if (!stack || !*stack || !cheap)
		return ;
	is_median = cheap->median;
	while (*stack != cheap)
	{
		if (st_na == 'a')
		{
			if (is_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (st_na == 'b')
		{
			if (is_median)
				rb(stack);
			else
				rrb(stack);
		}
		else
			return ;
	}
}
