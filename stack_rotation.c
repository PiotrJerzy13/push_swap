/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:06:34 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 19:48:43 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->fwd)
		temp = temp->fwd;
	temp->fwd = new;
	new->bwd = temp;
	new->fwd = NULL;
}

void	rotate(t_stack_node **top)
{
	t_stack_node	*stack;
	t_stack_node	*stack2;

	if (!*top || !(*top)->fwd)
		return ;
	stack = *top;
	stack2 = (*top)->fwd;
	*top = stack2;
	stack2->bwd = NULL;
	ft_stack_add_back(top, stack);
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
