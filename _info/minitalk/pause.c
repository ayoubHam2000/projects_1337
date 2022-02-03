/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:10:35 by aben-ham          #+#    #+#             */
/*   Updated: 2021/12/02 21:36:55 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void handler(int a)
{
	write(1, "signle is received\n", 20);
}

int main()
{
	signal(SIGUSR1, handler);
	while (1)
	{
		pause();
		write(1, "after pause\n", 12);
		sleep(1);
	}
	return (0);
}
