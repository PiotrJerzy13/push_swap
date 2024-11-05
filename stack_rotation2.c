/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:50:27 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/11/05 18:59:26 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_r(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*second_to_last;

	if (!head || !(*head) || !(*head)->fwd)
		return ;
	last = *head;
	second_to_last = NULL;
	while (last->fwd)
	{
		second_to_last = last;
		last = last->fwd;
	}
	second_to_last->fwd = NULL;
	last->fwd = *head;
	last->bwd = NULL;
	(*head)->bwd = last;
	*head = last;
}

void	rra(t_stack_node **a)
{
	reverse_r(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_r(b);
	write(1, "rrb\n", 4);
}
