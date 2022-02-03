/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:50:51 by aben-ham          #+#    #+#             */
/*   Updated: 2021/12/02 21:16:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void handler(int num)
{
	write(1, "I Won't die\n", 13); 
}

int main()
{
	signal(SIGINT, handler); //interrupt
	signal(SIGTERM, handler);
	signal(SIGKILL, handler);
	signal(SIGSEGV, handler);
	while (1)
	{
		write(1, "Wasting your cycles\n", 21);
		usleep(1000000);
	}
}