/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:54:56 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/24 18:58:04 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_no_split(t_stack_node **a, int argc, char **argv)
{
	int				i;
	long			val;
	t_stack_node	*new_node;

	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[i]);
		if (!handle_errors(a, argv[i], val))
		{
			free_errors(a, NULL, argc);
		}
		new_node = create_node(val);
		if (!new_node)
		{
			free_errors(a, NULL, argc);
		}
		if (!(*a))
			*a = new_node;
		else
			append_node(a, new_node);
		i++;
	}
	return (1);
}

void	free_errors(t_stack_node **a, char **argv, int argc)
{
	if (a)
		release_stack(a);
	if (argc == 2 && argv)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}
