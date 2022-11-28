/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigusr1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:01:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/28 00:06:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

__sighandler_t	handle_sigusr1(int signal)
{
	write(STDOUT_FILENO, "Estou a funcionar!!!!!\n", 24);
}