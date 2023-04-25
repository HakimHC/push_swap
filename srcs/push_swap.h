/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:20:37 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 17:53:04 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

t_list	*args_to_list(char *args[], int i);
void	printf_list(t_list *head);
void	rev_rot(t_list *head, char *mvmt);
void	rrr(t_list *a, t_list *b);
void	rotate(t_list *a, char *mvmt);
void	rr(t_list *a, t_list *b);
void	ft_nothing(void *a);
void	swp(t_list *head, char *mvmt);
void	ss(t_list *a, t_list *b);
t_list	*push(t_list **a, t_list **b, char stack);
int	is_ordered(t_list *head);
int	contains_duplicates(t_list *head);
void	ft_error_handler(t_list *head);
void	three_args(t_list **a, t_list **b);
int	chunks_to_b(t_list **a, t_list **b, int *chunks);
int	chunks_left(t_list *a, int *chunks, int i);
int	element_in_range(char *elem, int *chunks, int i);
void	chunks_to_a(t_list **a, t_list **b);
int	ft_range_calculator(t_list *head);
int	*ft_chunk_generator(t_list *head);
void	determine_rotate(int *top, int *bottom, t_list **b);
int	ft_min_max(t_list *head, char m);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);

#endif
