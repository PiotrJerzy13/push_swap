/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:12 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/05/21 18:41:10 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **a, t_stack_node *new_node)
{
	t_stack_node	*last;

	last = *a;
	while (last->fwd)
		last = last->fwd;
	last->fwd = new_node;
	new_node->bwd = last;
}

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
