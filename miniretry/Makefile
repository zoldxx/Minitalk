# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 11:58:25 by dberreby          #+#    #+#              #
#    Updated: 2023/04/13 15:10:58 by dberreby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= server.c ft_printf.c utils.c

OBJ 			= $(SRC:.c=.o)

CSRC			= client.c ft_printf.c utils.c

COBJ 			= $(CSRC:.c=.o)

SRC_BONUS			= server_bonus.c ft_printf.c utils.c

OBJ_BONUS			= $(SRC_BONUS:.c=.o)

CSRC_BONUS			= client_bonus.c ft_printf.c utils.c

COBJ_BONUS 			= $(CSRC_BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
SERV			= server
CLI				= client
BSERV			= server_bonus
BCLI			= client_bonus

all:			$(SERV) $(CLI)

bonus:			$(BSERV) $(BCLI)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -c $< -o $@

$(SERV): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(SERV)

$(CLI): $(COBJ)
	$(CC) $(CFLAGS) $(COBJ) -o $(CLI)

$(BSERV): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BSERV)

$(BCLI): $(COBJ_BONUS)
	$(CC) $(CFLAGS) $(COBJ_BONUS) -o $(BCLI)

clean:
				$(RM) $(OBJ) $(COBJ) $(OBJ_BONUS) $(COBJ_BONUS)

fclean:			clean
					$(RM) $(SERV) $(CLI) $(BSERV) $(BCLI)

re:				fclean all

.PHONY:			all clean fclean re