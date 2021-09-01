
CLIENT			= client
SERVER			= server
LIBFT			= libft/libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all:			$(SERVER) $(CLIENT)

$(SERVER):		server.c $(LIBFT)
				$(CC) $(CFLAGS) server.c terminate.c $(LIBFT) -o $(SERVER)

$(CLIENT):		client.c $(LIBFT)
				$(CC) $(CFLAGS) client.c terminate.c $(LIBFT) -o $(CLIENT)

make fclean:
				rm -rf $(SERVER) $(CLIENT)
