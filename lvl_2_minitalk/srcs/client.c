/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:15:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/28 00:11:43 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	args_check(int argc, char **argv)
{
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	if (argv[1][0] < '0' || argv[1][0] > '9')
		handle_errors("Invalid PID argument");
}

int main(int argc, char **argv)
{
	args_check(argc, argv);
	signal(SIGINT, handle_sigusr1);
	
	
	return (EXIT_SUCCESS);
}