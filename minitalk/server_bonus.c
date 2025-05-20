/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:20 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/01/23 17:39:54 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	get_signal(int signal, siginfo_t *info, void *content)
{
	static int	count;
	static char	c;

	(void)content;
	if (signal == SIGUSR1)
		c <<= 1;
	else if (signal == SIGUSR2)
	{
		c <<= 1;
		c |= 1;
	}
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		count = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Errore nell invio della conferma");
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = get_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("PID DEL SERVER: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("errore nella ricezione del segnale");
		return (-1);
	}
	while (1)
		pause();
	return (0);
}
