/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:15:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/29 01:13:39 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
} */
int	print_character(int *char_binary)
{
	int				binary_table;
	int				current_bit;
	unsigned char	ch;

	binary_table = 128;
	current_bit = 7;
	ch = 0;
	while (true)
	{
		if (current_bit == -1)
			break;
		ft_printf("char_binary[%d] = %d\n", current_bit, char_binary[current_bit]);
		if ((ch | char_binary[current_bit]) == 1)
			ch = ch | binary_table;
		binary_table /= 2;
		current_bit--;
	}
	write(1, &ch, 1);
	return (EXIT_SUCCESS);
}

// 1 -> 00000001
// a -> 01100001

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int	bits[8];
	static int	current_bit = 7;

	(void)ucontent;
	if (signum == SIGUSR1)
		bits[current_bit] = 1;
	if (signum == SIGUSR2)
		bits[current_bit] = 0;
	current_bit--;
	if (current_bit < 0)
	{
		print_character(bits);
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Server failed to send SIGUSR1");
}

void	create_signal(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	create_signal();
	while (1)
		pause();
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