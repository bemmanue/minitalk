# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 19:11:35 by bemmanue          #+#    #+#              #
#    Updated: 2021/10/07 19:11:38 by bemmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
CLIENT			=	client

SERVER_SRCS		=	./sources/server.c		\
					./sources/terminate.c
CLIENT_SRCS		=	./sources/client.c		\
					./sources/get_pid.c		\
					./sources/terminate.c

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

all:				lib $(SERVER) $(CLIENT)

.c.o:
					$(CC) $(CFLAGS) -I./includes/ -c $< -o $@

$(SERVER):			$(SERVER_OBJS)
					$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_PATH) -lft -o $(SERVER)

$(CLIENT):			$(CLIENT_OBJS)
					$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_PATH) -lft -o $(CLIENT)

lib:
					$(LIBFTMAKE)

clean:
					$(MAKE) clean -sC $(LIBFT_PATH)
					$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:				clean
					$(MAKE) fclean -sC $(LIBFT_PATH)
					rm -rf $(SERVER) $(CLIENT)

re:         		fclean all

.PHONY:				all clean lib fclean re
