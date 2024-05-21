/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:35:55 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/21 20:11:58 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
}	t_stack_node;

// Function declarations

// Stack operations
int				dll_swap(t_stack_node **current);
void			sa(t_stack_node **head);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **head);
void			rra(t_stack_node **head);
void			rrb(t_stack_node **head);
void			rrr(t_stack_node **a, t_stack_node **b);

// Stack utilities
int				stack_length(t_stack_node *head);
bool			stack_ordered(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **a, t_stack_node *new_node);
void			print_stack(t_stack_node *a);

// Error handling
bool			handle_errors(t_stack_node **a, char *argv, long n);
void			free_errors(t_stack_node **a, char **argv, int argc);
int				error_nondigit(char *str);
int				error_duplicated(t_stack_node *a, long n);

// Node creation
t_stack_node	*create_node(int value);

// Sorting algorithms
void			quick_sort(t_stack_node **a, t_stack_node **b, int size);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
int				find_median(t_stack_node *head, int size);
void			populate_array(t_stack_node *head, int *values, int size);
void			insertion_sort(int *values, int size);
void			p(t_stack_node **a, t_stack_node **b, int median, int *count_a);

// Utility functions
char			**ft_split(char const *s, char c);
void			free_array(char **array);
long			ft_atol(const char *str);

#endif // PUSH_SWAP_H