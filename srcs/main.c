/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/29 20:35:20 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	**split;

	b = 0;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	a = args_to_list(split, 0);
	ft_error_handler(a);
	// if (ft_lstsize(a) == 3)
	// 	three_args(&a, &b);
	//
	rev_rot(a, "rra");
	printf_list(a);
	// ft_printf("%d\n", ft_atoi(a->content) >> 1);
	ft_lstclear(&a, &ft_nothing);
	ft_lstclear(&b, &ft_nothing);
	// system("leaks -q push_swap");
}
