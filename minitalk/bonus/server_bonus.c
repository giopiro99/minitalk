/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:20 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:46:08 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/**
 * @brief Signal handler that reconstructs a character from received bits.
 *
 * Receives signals SIGUSR1 and SIGUSR2 representing bits 0 and 1 respectively,
 * builds a character bit by bit, and prints it when complete.
 * After receiving 8 bits (one character), sends a confirmation signal (SIGUSR1)
 * back to the sender process.
 *
 * @param signal The received signal (SIGUSR1 or SIGUSR2).
 * @param info Pointer to siginfo_t structure containing sender info.
 * @param content Unused context pointer.
 */
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
		ft_printf(1,"%c", c);
		count = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf(2, "Errore nell invio della conferma");
	}
}

/**
 * @brief Entry point for the server program.
 *
 * Sets up signal handlers for SIGUSR1 and SIGUSR2 using sigaction,
 * configuring them to use the get_signal function with extended info.
 * Prints the server's PID for client reference, then waits indefinitely
 * for incoming signals to process bitwise messages.
 *
 * @return int Returns 0 on normal exit, -1 on error setting up signals.
 */
int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = get_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf(1, "PID DEL SERVER: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf(2, "errore nella ricezione del segnale");
		return (-1);
	}
	while (1)
		pause();
	return (0);
}
