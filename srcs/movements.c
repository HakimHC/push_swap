/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:35:36 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 00:45:27 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

//
// int	main(int argc, char *argv[])
// {
// 	t_list	*a;
// 	t_list	*b;
//
// 	b = 0;
// 	a = args_to_list(argv + 1, 0);
// 	// /* ====== TEST SUBJECT ==== */
//
// 	swp(a, "sa");
// 	a = push(&a, &b, 'b');
// 	a = push(&a, &b, 'b');
// 	a = push(&a, &b, 'b');
// 	rr(a, b);
// 	rrr(a, b);
// 	swp(a, "sa");
// 	b = push(&a, &b, 'a');
// 	b = push(&a, &b, 'a');
// 	b = push(&a, &b, 'a');
// 	
// 	// /* ======================== */
// 	// a = push(&a, &b, 'b');
// 	// b = push(&a, &b ,'a');
// 	printf_list(a);
// 	ft_lstclear(&a, &ft_nothing);
// 	ft_lstclear(&b, &ft_nothing);
// 	system("leaks -q a.out");
// }
