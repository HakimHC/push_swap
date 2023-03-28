/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:35:36 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 19:07:33 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swp(t_list *head, char *mvmt)
{
	char	*aux;

	if (ft_lstsize(head) <= 1)
		return ;
	aux = head->content;
	head->content = head->next->content;
	head->next->content = aux;
	if (mvmt)
		ft_printf("%s\n", mvmt);
}

void	ss(t_list *a, t_list *b)
{
	swp(a, 0);
	swp(b, 0);
	ft_printf("ss\n");
}

t_list	*push(t_list **a, t_list **b, char stack)
{
	t_list	*aux;
	t_list	*head;

	if (stack == 'b')
	{
		if (!*a)
			return (*a);
		head = (*a)->next;
		aux = ft_lstnew((*a)->content);
		ft_lstadd_front(b, aux);
		ft_lstdelone(*a, &ft_nothing);
		ft_printf("pb\n");
		return (head);
	}
	if (!*b)
		return (*b);
	head = (*b)->next;
	aux = ft_lstnew((*b)->content);
	ft_lstadd_front(a, aux);
	ft_lstdelone(*b, &ft_nothing);
	ft_printf("pa\n");
	return (head);
}
