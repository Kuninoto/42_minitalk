/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:15:39 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/27 23:25:13 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	
	
	return (EXIT_SUCCESS);
}