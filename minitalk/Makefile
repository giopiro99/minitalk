# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 11:42:49 by fzuccaro          #+#    #+#              #
#    Updated: 2025/01/27 14:02:24 by gpirozzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}

OBJ_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}
OBJ_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_CLIENT_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_SERVER_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER_BONUS)


%.o: %.c
		@${CC} -c ${CFLAGS} -I$(LIBFT_DIR) $< -o $@

clean:
		rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
		@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

