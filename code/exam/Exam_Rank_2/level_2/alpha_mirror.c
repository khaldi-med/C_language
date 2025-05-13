/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:07:06 by jbadenho          #+#    #+#             */
/*   Updated: 2017/03/07 16:33:14 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
		int 	i;
		char	j;

		i = 0;
		if (argc == 2)
		{
			while (argv[1][i])
			{
				if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
					j = 'M' - (argv[1][i] - 'N');
				else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
					j = 'm' - (argv[1][i] - 'n');
				else
					j = argv[1][i];
				write(1, &j, 1);
				i++;
			}
		}
		write(1, "\n", 1);
		return (0);
}
