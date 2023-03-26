/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:05:39 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/26 23:40:29 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_duplicates(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	while (curr->next)
	{
		next = curr->next;
		while (next)
		{
			if (ft_strcmp(curr->content, next->content) == 0)
				return (1);
			next = next->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*head;

	head = args_to_list(argv + 1, 0);
	ft_printf("%d\n", contains_duplicates(head));
}
