/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:12 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/23 14:43:47 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	size_t	i;
	int		pos_sign;
	long	output;

	i = 0;
	pos_sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos_sign = -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return (output * pos_sign);
}

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*pre_last;
	t_stack_node	*last;

	if (!*head || !(*head)->fwd)
		return ;
	pre_last = NULL;
	last = *head;
	while (last->fwd)
	{
		pre_last = last;
		last = last->fwd;
	}
	pre_last->fwd = NULL;
	last->bwd = NULL;
	last->fwd = *head;
	*head = last;
	(*head)->fwd->bwd = *head;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
