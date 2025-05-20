/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:20 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:44:02 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/**
 * @brief Signal handler that reconstructs a character from received signals.
 *
 * Each call shifts the static character `c` left by one bit.
 * If the signal is SIGUSR1, it appends a 0 bit; if SIGUSR2, appends a 1 bit.
 * After receiving 8 bits, prints the reconstructed character and resets counters.
 *
 * @param signal The received signal (SIGUSR1 or SIGUSR2).
 */
static void	get_signal(int signal)
{
	static int	count;
	static char	c;

	if (signal == SIGUSR1)
		c <<= 1;
	else
	{
		c <<= 1;
		c |= 1;
	}
	count++;
	if (count == 8)
	{
		ft_printf(1, "%c", c);
		count = 0;
		c = 0;
	}
}

/**
 * @brief Server program that receives and prints characters via signals.
 *
 * Prints its PID, then enters an infinite loop waiting for SIGUSR1 or SIGUSR2 signals.
 * These signals are handled by `get_signal` to reconstruct and print messages.
 *
 * @return int Exit status (never reached).
 */
int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf(1, "PID DEL SERVER: %d", pid);
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
	}
	return (0);
}
