/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:19:09 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/28 18:56:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

void	args_check(int argc, char **argv)
{
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	if (argv[1][0] < '0' || argv[1][0] > '9')
		handle_errors("Invalid PID argument");
}

void	send_char(int sv_pid, unsigned char c)
{
	int	nbr_bits;

	nbr_bits = 8;
	while (nbr_bits--)
	{
		if (c & 0b10000000)
			kill(sv_pid, SIGUSR1);
		else
			kill(sv_pid, SIGUSR2);
		usleep(1);
		c <<= 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t	sv_pid;
	char	*msg;

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	*msg = argv[2];
	while (*msg)
	{
		send_char(sv_pid, *msg);
		msg++;
	}
	return (EXIT_SUCCESS);
}

// A 01000001
// - 10000000