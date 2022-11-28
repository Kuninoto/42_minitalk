/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:19:24 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/28 18:58:25 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

void	handle_sigusr(int signum)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, 1);
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	if (!pid)
    {
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
    }

	ft_printf("SERVER PID = %d\n", pid);
	while (1)
	{		
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
	}
	return (EXIT_SUCCESS);
}
/*
	if (signum == SIGUSR1)
		write(1, "1", 1);
	else if (signum == SIGUSR2)
		write(1, "0", 1);

	
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
    {
        printf("C = %c\n", c);
        c = 0;
    }

*/