/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:43:05 by aben-ham          #+#    #+#             */
/*   Updated: 2021/12/03 19:33:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

/*
https://man7.org/linux/man-pages/man2/sigaction.2.html

int sigaction(	int signum, 
				const struct sigaction *act,
                struct sigaction *oldact
);

* The sigaction structure is defined as something like:

	struct sigaction {
		void     (*sa_handler)(int);
		void     (*sa_sigaction)(int, siginfo_t *, void *);
		sigset_t   sa_mask;
		int        sa_flags;
		void     (*sa_restorer)(void);
	};

sa_handler specifies the action to be associated with signum and
is be one of the following:

	* SIG_DFL for the default action.

	* SIG_IGN to ignore this signal.

	* A pointer to a signal handling function.  This function
		receives the signal number as its only argument.

* On some architectures a union is involved: do not assign to both
       sa_handler and sa_sigaction.

* sa_mask specifies a mask of signals which should be blocked
(i.e., added to the signal mask of the thread in which the signal
handler is invoked) during execution of the signal handler.  In
addition, the signal which triggered the handler will be blocked,
unless the SA_NODEFER flag is used.

sigset_t ens1;
sigemptyset(&ens1); //init set of signals
sigaddset(&ens1,SIGINT); //add signal to the set

//==============
* sa_flags specifies a set of flags which modify the behavior of
the signal.  It is formed by the bitwise OR of zero or more of
the following:

* The sa_restorer field is not intended for application use.
(POSIX does not specify a sa_restorer field.)  Some further
details of the purpose of this field can be found in
sigreturn(2).




*/

void handler(int num)
{
	write(1, "Receiving a signal USR1\n", 24);
	sleep(15);
	write(1, "End\n", 4);
}

int main()
{
	
	struct sigaction sa;
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	
	sa.__sigaction_u.__sa_handler = handler;
	sa.sa_mask = set;
	sa.sa_flags = 0;
	
	sigaction(SIGUSR1, &sa, NULL);
	pause();
	write(1, "After Pause\n", 12);
	sleep(15);

	return (0);
}

/*
when we don't sent an interrupt signal
output
	Receiving a signal USR1
	End
	After Pause
when we sent an interrupt signal after SIGUSR1
output
	Receiving a signal USR1
	End
*/