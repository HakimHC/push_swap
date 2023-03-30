/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:44:19 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/31 00:00:58 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_list *head, char *mvmt)
{
	char	*aux;
	t_list	*curr;
	char	*next;
	char	*first;

	if (!head)
		return ;
	if (!head || ft_lstsize(head) == 1)
		return ;
	if (ft_lstsize(head) == 2)
	{
		swp(head, 0);
		return;
	}
	first = ft_lstlast(head)->content;
	aux = head->content;
	curr = head->next;
	while (curr->next)
	{
		next = curr->content;
		curr->content = aux;
		aux = next;
		curr = curr->next;
	}
	curr->content = aux;
	head->content = first;
	if (mvmt)
		ft_printf("%s\n", mvmt);
}

void	rrr(t_list *a, t_list *b)
{
	rev_rot(a, 0);
	rev_rot(b, 0);
	ft_printf("rrr\n");
}

void	rotate(t_list *a, char *mvmt)
{
	t_list	*curr;
	t_list	*last;
	char	*aux;

	if (!a || ft_lstsize(a) == 1)
		return ;
	if (ft_lstsize(a) == 2)
	{
		swp(a, 0);
		return;
	}
	last = ft_lstlast(a);
	aux = a->content;
	a->content = last->content;
	last->content = aux;
	curr = a;
	while (curr->next->next)
	{
		aux = curr->content;
		curr->content = curr->next->content;
		curr->next->content = aux;
		curr = curr->next;
	}
	if (mvmt)
		ft_printf("%s\n", mvmt);
}

void	rr(t_list *a, t_list *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	ft_nothing(void *a)
{
	(void) a;
}

