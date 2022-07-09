# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:09:53 by hyna              #+#    #+#              #
#    Updated: 2022/07/09 18:20:42 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV = server
CLI = client
CC = cc
CCFLAGS = -Wall -Werror -Wextra
INC_LINK = -I./inc
LIBS = -L./lib/ft_printf -lftprintf\

SRV_SRCS_NAME = srv_main.c\

CLI_SRCS_NAME = cli_main.c\

SRCS_PATH = ./srcs
SRV_SRCS = $(addprefix $(SRCS_PATH)/, $(SRV_SRCS_NAME))
CLI_SRCS = $(addprefix $(SRCS_PATH)/, $(CLI_SRCS_NAME))

SRV_OBJS_NAME = $(SRV_SRCS_NAME:.c=.o)
CLI_OBJS_NAME = $(CLI_SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
SRV_OBJS = $(addprefix $(OBJS_PATH)/, $(SRV_OBJS_NAME))
CLI_OBJS = $(addprefix $(OBJS_PATH)/, $(CLI_OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS) 
	@$(MAKE) -C ./lib/ft_printf
	$(CC) $(CCFLAGS) $(LIBS) -o $(SRV) $(SRV_OBJS)
	$(CC) $(CCFLAGS) $(LIBS) -o $(CLI) $(CLI_OBJS)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

clean :
	@$(MAKE) -C ./lib/libft clean
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf ./lib/ft_printf/libftprintf.a
	rm -rf $(SRV) $(CLI)

re : fclean all

.PHONY: all clean fclean
