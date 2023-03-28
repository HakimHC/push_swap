/* ************************************************************************** */
/*                                                                            */
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

#endif
