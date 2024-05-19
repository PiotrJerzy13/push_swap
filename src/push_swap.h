/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:35:55 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/04/28 22:12:49 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
}	t_stack_node;

// Constants to represent success and failure
# define TRUE 	1
# define FALSE 	0

// Function declarations
int				dll_swap(t_stack_node **current);
void			free_stack(t_stack_node **stack);
int				error_nondigit(char *str);
t_stack_node	*create_node(int value);
void			sa(t_stack_node **head);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **head);
void			rra(t_stack_node **head);
int				stack_length(t_stack_node *head);
char			**ft_split(char const *s, char c);
void			free_array(char **array);
void			quick_sort(t_stack_node **a, t_stack_node **b, int size);
int				find_median(t_stack_node *head, int size);

#endif // PUSH_SWAP_H
