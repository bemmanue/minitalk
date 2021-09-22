
CLIENT			= client
SERVER			= server
LIBFT			= libft/libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all:			$(SERVER) $(CLIENT)

$(SERVER):		sources/server.c $(LIBFT)
				$(CC) $(CFLAGS) sources/server.c sources/terminate.c $(LIBFT) -o $(SERVER)

$(CLIENT):		sources/client.c $(LIBFT)
				$(CC) $(CFLAGS) sources/client.c sources/terminate.c sources/check_pid.c $(LIBFT) -o $(CLIENT)

make fclean:
				rm -rf $(SERVER) $(CLIENT)
