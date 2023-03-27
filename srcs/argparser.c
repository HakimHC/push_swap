/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:25:45 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 00:48:20 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**stack_to_arr(char *stack)
{
	char	**arr;

	arr = ft_split(stack, 32);
	return (arr);
}

t_list	*args_to_list(char *args[], int i)
{
	t_list	*node;

	if (!args[i])
		return (NULL);
	node = ft_lstnew((char *) args[i]);
	node->next = args_to_list(args, ++i);
	return (node);
}

void	printf_list(t_list *head)
{
	if (!head)
		return ;
	ft_printf("%s\n", (char *) head->content);
	printf_list(head->next);
}
//
// int	main(int argc, char *argv[])
// {
// 	t_list	*head;
//
// 	head = args_to_list(argv, 0);
// 	printf_list(head);
// 	//
// 	// ft_printf("%A", argv + 1);
// 	// ft_printf("-\na\n");
// }
