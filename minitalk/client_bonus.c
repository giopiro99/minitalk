/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:08 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/01/23 17:31:44 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static int	g_confirmation = 0;

static void	conf_handler(int signal)
{
	if (signal == SIGUSR1)
		g_confirmation = 1;
}

static void	wait_conf(void)
{
	while (!g_confirmation)
		pause();
	if (g_confirmation == 1)
		ft_printf("Conferma ricevuta\n");
	g_confirmation = 0;
}

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

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || (ft_atoi(argv[1])) <= 0)
	{
		ft_printf("Errore inserire pid corretto e una stringa");
		return (-1);
	}
	sa.sa_handler = conf_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Errore");
		return (-1);
	}
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
