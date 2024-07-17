/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:06:40 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/17 14:07:38 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libtft/libft.h"

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	struct s_stack_node	*target_node;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
	int					node;
	int					place;
	int					price;
	bool				median;
	bool				target;
}	t_stack_node;

typedef struct s_nodes
{
	t_stack_node	*cheap;
	t_stack_node	*node;
}	t_nodes;

#endif
