/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:47:25 by nhochstr          #+#    #+#             */
/*   Updated: 2020/02/17 20:01:59 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int main()
{
	int y = 0;
	int z = 0;
	/*int i = 0;
	int j = 0;
	y = printf("Test 1: Bonjour%5c + %*.*s - %-13p - %010d - %-20.12u - %-10.9x - %-10.9X$\n", 'N', 10, 5, "Lauraa", "héhé", -118218, -1, -1, -1234332);
	z = ft_printf("Test 1: Bonjour%5c + %*.*s - %-13p - %010i - %-20.12u - %-10.9x - %-10.9X$\n", 'N', 10, 5, "Lauraa", "héhé", -118218, -1, -1, -1234332);
	printf("%d - %d\n", y, z);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s\n", "Hahaha");
	i = ft_printf("%s\n", "Hahaha");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("Hello World%%\n");
	i = ft_printf("Hello World%%\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("Black Lightning\n");
	i = ft_printf("Black Lightning\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("");
	i = ft_printf("");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.i$\n", 44);
	i = ft_printf("%.i$\n", 44);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0i$\n", 0);
	i = ft_printf("%.0i$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.d$\n", 0);
	i = ft_printf("%.d$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%d$\n", 0);
	i = ft_printf("%d$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.u$\n", 0);
	i = ft_printf("%.u$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0x$\n", 0);
	i = ft_printf("%.0x$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.0X$\n", 0);
	i = ft_printf("%.0X$\n", 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%c", '\0');
	i = ft_printf("%c", '\0');
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%---4c\n", 'a');
	i = ft_printf("%---4c\n", 'a');
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s\n", NULL);
	i = ft_printf("%s\n", NULL);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%s", "");
	i = ft_printf("%s", "");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%.2s", NULL);
	i = ft_printf("%.2s", NULL);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%00-12.15m012$\n");
	i = ft_printf("%00-12.15m012$\n");
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("hello ca%----4c$ %1c va %-6c ??\n", 'a', '\n', 0);
	i = ft_printf("hello ca%----4c$ %1c va %-6c ??\n", 'a', '\n', 0);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 23: %1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.ld, %1.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	i = ft_printf("test 23: %1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 12: %0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.ld, %0.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	i = ft_printf("test 12: %0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 8, -12, 123456789, 0, -12345678, 'a', -2147483648, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*ld, %*d\n", -4, 8, -4, -12, -4, 123456789, -4, 0, -4, -12345678, -4, 'a', -4, -2147483648, -4, 2147483647);
	i = ft_printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", -4, 8, -4, -12, -4, 123456789, -4, 0, -4, -12345678, -4, 'a', -4, -2147483648, -4, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*ld, %*d\n", 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483648, 0, 2147483647);
	i = ft_printf("test 34: %*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", 0, 8, 0, -12, 0, 123456789, 0, 0, 0, -12345678, 0, 'a', 0, -2147483648, 0, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 34: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*ld, %*.*d\n", -2, 0, 8, -2, 0, -12, -2, 0, 123456789, -2, 0, 0, -2, 0, -12345678, -2, 0, 'a', -2, 0, -2147483648, -2, 0, 2147483647);
	i = ft_printf("test 34: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", -2, 0, 8, -2, 0, -12, -2, 0, 123456789, -2, 0, 0, -2, 0, -12345678, -2, 0, 'a', -2, 0, -2147483648, -2, 0, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("test 211: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*ld, %*.*d\n", 4, 3, 8, 4, 3, -12, 4, 3, 123456789, 4, 3, 0, 4, 3, -12345678, 4, 3, 'a', 4, 3, -2147483648, 4, 3, 2147483647);
	i = ft_printf("test 211: %*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", 4, 3, 8, 4, 3, -12, 4, 3, 123456789, 4, 3, 0, 4, 3, -12345678, 4, 3, 'a', 4, 3, -2147483648, 4, 3, 2147483647);
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	*/
	/*
	int		a = 2;
	int		b = 3;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	z = printf("test 211: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	y = ft_printf("test 211: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("test 444: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	y = ft_printf("test 444: %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -1, 'a', 0, 'a', 0, 'a', 0, 'a');
	y = ft_printf("f test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -1, 'a', 0, 'a', 0, 'a', 0, 'a');
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	//z = printf("r test 510: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	z = printf("r test 510: %c$\n", 0);
	y = ft_printf("f test 510: %c$\n", 0);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: %ca%1igr%%%-1c%-20.3X%%%*.4X\n", '\0', 2147483647, 'k', -2147483647, 5, 0);
	y = ft_printf("f test 510: %ca%1igr%%%-1c%-20.3X%%%*.4X\n", '\0', 2147483647, 'k', -2147483647, 5, 0);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: %XCPc48t T3CuJ%16cs3WQOAo0%-*.0i%.3iN\n", -2147483647, '\0', 8, 0, 2147483647);
	y = ft_printf("f test 510: %XCPc48t T3CuJ%16cs3WQOAo0%-*.0i%.3iN\n", -2147483647, '\0', 8, 0, 2147483647);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 510: TH%%%u%c%4.0xNDjWuuN%-*c\n", -361203380, '\0', 0, 5, 'B');
	y = ft_printf("f test 510: TH%%%u%c%4.0xNDjWuuN%-*c\n", -361203380, '\0', 0, 5, 'B');
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("%");//test 11
	y = ft_printf("%");
	(void)z;
	printf("%d\n", y);
	printf("------------------------------------------------------------------------------------------------------------------\n")
	z = printf("%-5");//test 15
	y = ft_printf("%-5");
	(void)z;
	printf("%d\n", y);
	printf("------------------------------------------------------------------------------------------------------------------\n")
	z = printf("r test 511: %    .4d\n", 30);//327
	y = ft_printf("f test 511: %    .4d\n", 30);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 511: %0-00005i\n", 5);
	y = ft_printf("f test 511: %0-00005i\n", 5);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	z = printf("r test 512: %p\n", NULL);
	y = ft_printf("f test 512: %p\n", NULL);
	printf("%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	j = printf("%---4c", 'a');
	j = printf("%---4c", 'b');
	j = printf("%---4c\n", 'c');
	i = ft_printf("%---4c", 'a');
	i = ft_printf("%---4c", 'b');
	i = ft_printf("%---4c\n", 'c');
	printf("%d - %d\n", j, i);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	*/
	//z = printf("%5");//327
	y = ft_printf("%5c", 'a');
	printf("\n%d - %d\n", z, y);
	printf("------------------------------------------------------------------------------------------------------------------\n");
	while (1);
	return 0;
}
/*
./disable-test f && ./disable-test "*_as*" && ./disable-test "*_l_*" && ./disable-test "*_ll_*" && ./disable-test "*_h_*" && ./disable-test "*_hh_*" && ./disable-test "*ljas*" && ./disable-test "*_ll*" && ./disable-test "*_hh*"
./disable-test "*_f_*" && ./disable-test mix && ./disable-test "*_ld_*" && ./disable-test o && ./disable-test "*af*" && ./disable-test "*_diff_*" && ./disable-test "*_hash_*"  && ./disable-test "*_e_*" && ./disable-test "*_g_*"
./disable-test "*_a_*"  && ./disable-test "*notmandatory*" && ./disable-test "*lmin*" && ./disable-test "*lmax*" && ./disable-test "*hmin*" && ./disable-test "*hmax*" && ./disable-test "*as_*"
./disable-test "*_o_*"  && ./disable-test "*argnum*"
./disable-test 318 && ./disable-test 320 && ./disable-test 375 && ./disable-test 484 && ./disable-test 486 && ./disable-test 487 && ./disable-test 490 && ./disable-test 491 && ./disable-test 646 && ./disable-test 648 && ./disable-test 703 && ./disable-test 812 && ./disable-test 814 && ./disable-test 815
./disable-test "*_sp*" && ./disable-test "*sp_" && ./disable-test 2648  
*/