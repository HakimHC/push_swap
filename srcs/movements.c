/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:35:36 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/27 05:00:42 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swp(t_list *head, char stack)
{
	char	*aux;

	if (ft_lstsize(head) <= 1)
		return ;
	aux = head->content;
	head->content = head->next->content;
	head->next->content = aux;
	if (stack == 'a')
		ft_printf("sa\n");
	else if (stack == 'b')
		ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	swp(a, 'a');
	swp(b, 'b');
	ft_printf("ss\n");
}

void ft_nothing(void *a)
{
	return ;
}

t_list	*push(t_list *a, t_list *b, char stack)
{
	t_list	*aux;
	t_list	*head;

	if (stack == 'a')
	{
		if (!a)
			return (0);
		head = a->next;
		aux = ft_lstnew(a->content);
		// ft_printf("AUX DATA - %s\n", aux->content);
		ft_lstadd_front(&b, aux);
		ft_lstdelone(a, &ft_nothing);
		return (head);
	}
	else
	{
		if (!b)
			return (0);
		head = b->next;
		aux = ft_lstnew(b->content);
		ft_lstadd_front(&a, aux);
		// ft_lstdelone(b, &ft_nothing);
		return (head);
	}
}

void	rotate(t_list *a)
{
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = args_to_list(argv + 1, 0);
	swp(a, 'a');
	printf_list(a);
	// b = 0;
	// printf_list(a);
	// a = push(a, b, 'a');
	// printf_list(a);
	// // printf_list(b);
	// ft_printf("b - %s\n", b->content);
}
