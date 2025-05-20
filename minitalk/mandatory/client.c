/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:08 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:43:19 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/**
 * @brief Sends a string to a process bit by bit using signals.
 *
 * Iterates over each character in the string `str` and sends its bits
 * one by one to the process identified by `pid`. For each bit, it sends
 * SIGUSR2 if the bit is 1, or SIGUSR1 if the bit is 0. Uses usleep(50)
 * to pause briefly between sending bits to avoid overwhelming the receiver.
 *
 * @param pid The process ID to send signals to.
 * @param str The string message to send.
 */
static void	send_signal(int pid, char *str)
{
	char	c;
	int		num_bit;

	num_bit = 0;
	while (*str)
	{
		c = *str;
		while (num_bit < 8)
		{
			if ((c &(0b10000000 >> num_bit)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			num_bit++;
			usleep(50);
		}
		str++;
		num_bit = 0;
	}
}

/**
 * @brief Program entry point that validates arguments and sends a signal string.
 *
 * Checks if exactly two arguments are passed: a valid positive PID and a string.
 * If valid, calls `send_signal` to transmit the string to the process with PID.
 * Otherwise, prints "Error" to stderr and exits with status 1.
 *
 * @param argc Argument count.
 * @param argv Argument vector (argv[1] = PID, argv[2] = string).
 * @return int Exit status code.
 */
int	main(int argc, char **argv)
{
	if (argc == 3 && (ft_atoi(argv[1])) > 0)
		send_signal(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf(2, "Error\n");
		exit(1);
	}
	return (0);
}
