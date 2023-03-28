/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:05:39 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 19:15:16 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

int	ft_isinteger(char *element)
{
	long	n;

	n = ft_atol(element);
	ft_printf("%d\n", n);
	// ft_printf("%d\n", n);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	if (n == 0 && ft_strcmp(element, "0"))
		return (0);
	return (1);
}

void	print_n_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_handler(t_list *head)
{
	t_list	*curr;

	if (contains_duplicates(head))
		print_n_exit();
	curr = head;
	while (curr)
	{
		if (!ft_isinteger(curr->content))
			print_n_exit();
		curr = curr->next;
	}
}

//
// int	main(int argc, char **argv)
// {
// 	t_list	*head;
//
// 	head = args_to_list(argv + 1, 0);
// 	ft_printf("%d\n", contains_duplicates(head));
// }
