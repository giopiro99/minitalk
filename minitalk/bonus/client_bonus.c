/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:08 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:45:24 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/**
 * @brief Global variable to signal reception confirmation.
 */
static int	g_confirmation = 0;

/**
 * @brief Signal handler for confirmation.
 *
 * Sets `g_confirmation` to 1 upon receiving SIGUSR1,
 * indicating that the server has successfully received a character.
 *
 * @param signal The received signal.
 */
static void	conf_handler(int signal)
{
	if (signal == SIGUSR1)
		g_confirmation = 1;
}

/**
 * @brief Waits for reception confirmation from the server.
 *
 * Pauses execution until `g_confirmation` is set to 1,
 * then prints a confirmation message and resets the variable.
 */
static void	wait_conf(void)
{
	while (!g_confirmation)
		pause();
	if (g_confirmation == 1)
		ft_printf(1, "Conferma ricevuta\n");
	g_confirmation = 0;
}

/**
 * @brief Sends a string to the server process via signals.
 *
 * For each character in the string, sends individual bits as signals:
 * - SIGUSR2 for bit 1
 * - SIGUSR1 for bit 0
 * After sending each character, waits for confirmation of receipt.
 *
 * @param pid The server process PID to send signals to.
 * @param str The string to send.
 */
static void	send_signal(int pid, char *str)
{
	char	c;
	int		num_bit;

	while (*str)
	{
		c = *str;
		num_bit = 0;
		while (num_bit < 8)
		{
			if ((c &(0b10000000 >> num_bit)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			num_bit++;
			usleep(100);
		}
		wait_conf();
		str++;
	}
}

/**
 * @brief Client program that sends a string to a server via signals.
 *
 * Checks command line arguments, sets the signal handler
 * for confirmation, and sends the string to the specified PID.
 *
 * @param argc Number of arguments.
 * @param argv Arguments: argv[1] is the server PID, argv[2] is the string to send.
 * @return int 0 on success, -1 on error.
 */
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || (ft_atoi(argv[1])) <= 0)
	{
		ft_printf(2, "Errore inserire pid corretto e una stringa");
		return (-1);
	}
	sa.sa_handler = conf_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf(2, "Errore");
		return (-1);
	}
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
