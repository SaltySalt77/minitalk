# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 20:09:27 by hyna              #+#    #+#              #
#    Updated: 2022/07/10 20:13:59 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client
CC = cc
CCFLAGS = -Wall -Werror -Wextra
INC_LINK = -I./inc
LIBS = -L./lib/ft_printf -lftprintf\

SRV_SRCS_NAME = srv_main.c\
				srv_receiver.c\

CLI_SRCS_NAME = cli_main.c\
				cli_transmitter.c\

SRCS_PATH = ./srcs
SRV_SRCS = $(addprefix $(SRCS_PATH)/, $(SRV_SRCS_NAME))
CLI_SRCS = $(addprefix $(SRCS_PATH)/, $(CLI_SRCS_NAME))

SRV_OBJS_NAME = $(SRV_SRCS_NAME:.c=.o)
CLI_OBJS_NAME = $(CLI_SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
SRV_OBJS = $(addprefix $(OBJS_PATH)/, $(SRV_OBJS_NAME))
CLI_OBJS = $(addprefix $(OBJS_PATH)/, $(CLI_OBJS_NAME))

all : ft_printf $(NAME) $(NAME2)

$(NAME) : $(SRV_OBJS) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(NAME) $(SRV_OBJS)

$(NAME2) : $(CLI_OBJS) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(NAME2) $(CLI_OBJS)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

ft_printf :
	@$(MAKE) -C ./lib/ft_printf

clean :
	@$(MAKE) -C ./lib/ft_printf clean
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf ./lib/ft_printf/libftprintf.a
	rm -rf $(NAME) $(NAME2)

re : fclean all

.PHONY: all clean fclean
