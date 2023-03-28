/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:35:24 by hakahmed          #+#    #+#             */
/*   Updated: 2023/03/28 19:06:41 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	(void) argc;
	b = 0;
	a = args_to_list(argv + 1, 0);
	ft_error_handler(a);
	// if (!is_ordered(a))
	// 	ft_printf("NOT ORDERED.....\n");
	// // /* ====== TEST SUBJECT ==== */
	//
	// swp(a, "sa");
	// a = push(&a, &b, 'b');
	// a = push(&a, &b, 'b');
	// a = push(&a, &b, 'b');
	// rr(a, b);
	// rrr(a, b);
	// swp(a, "sa");
	// b = push(&a, &b, 'a');
	// b = push(&a, &b, 'a');
	// b = push(&a, &b, 'a');
	// 
	// // /* ======================== */
	// // a = push(&a, &b, 'b');
	// // b = push(&a, &b ,'a');
	// // printf_list(a);
	// if (is_ordered(a))
	// 	ft_printf("ORDERED.....\n");
	ft_lstclear(&a, &ft_nothing);
	ft_lstclear(&b, &ft_nothing);
	// system("leaks -q a.out");
}
