/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 09:01:35 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/03/24 07:09:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	malloc(42);
	malloc(84);
	malloc(3725);
	malloc(48847);
	malloc(99929194294967286);
	show_alloc_mem();
	return (0);
}
