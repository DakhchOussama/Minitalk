CFLAGC = -Wall -Wextra -Werror
CC = gcc
c_src = src/minitalk_utils.c
cb_src = src/minitalk_utils.c
c_obj=$(c_src:.c=.o)
cb_obj=$(cb_src:.c=.o)
server_src = src/server.c
client_src = src/client.c
header_src = src/minitalk.h
header_bonus = bonus_src/minitalk_bonus.h
server_bonus = bonus_src/server_bonus.c
client_bonus = bonus_src/client_bonus.c
server_b = server_bonus
client_b = client_bonus
server = server 
client = client
all: $(server) $(client)

$(server):$(c_obj) $(header_src)
	$(CC) $(CFLAGS) $(server_src) $(c_obj) -o $(server)
$(client):$(c_obj) $(header_src)
	$(CC) $(CFLAGS) $(client_src) $(c_obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@
bonus : $(server_b) $(client_b)

$(server_b):$(cb_obj) $(header_bonus)
	$(CC) $(CFLAGS) $(server_bonus) $(cb_obj) -o $(server_b)
$(client_b):$(cb_obj) $(header_bonus)
	$(CC) $(CFLAGS) $(client_bonus) $(cb_obj) -o $(client_b)
clean:
	rm -rf $(c_obj) $(cb_obj)
fclean: clean
	rm -rf $(client) $(server) $(server_b) $(client_b)
re: fclean all