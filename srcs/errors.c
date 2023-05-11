/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:05:39 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/04 12:02:38 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

#include "push_swap.h"

int	contains_duplicates(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	if (!curr)
		return (1);
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
	long	sign;
	int		i;

	n = 0;
	sign = 1;
	i = -1;
	while (ft_isspace(element[++i]))
		;
	if (element[i] == '-' || element[i] == '+')
	{
		if (element[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(element[i]))
	{
		n = (n * 10) + (element[i] - 48);
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	while (ft_isspace(element[i++]))
		;
	return (!(element[i - 1]));
}

void	print_n_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_handler(t_list *head)
{
	t_list	*curr;

	if (contains_duplicates(head))
		print_n_exit();
	curr = head;
	while (curr)
	{
		if (!ft_isinteger(curr->content)
			|| ft_strlen(curr->content) < 1)
			print_n_exit();
		curr = curr->next;
	}
}

void	err_han(t_list *a)
{
	if (ft_lstsize(a) == 1)
	{
		ft_error_handler(a);
		exit(EXIT_SUCCESS);
	}
	ft_error_handler(a);
	if (is_ordered(a))
		exit(EXIT_SUCCESS);
}
//
// int	main(int argc, char **argv)
// {
// 	t_list	*head;
//
// 	head = args_to_list(argv + 1, 0);
// 	ft_printf("%d\n", contains_duplicates(head));
// }
