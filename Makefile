# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 20:09:27 by hyna              #+#    #+#              #
#    Updated: 2022/07/09 20:12:03 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV = server
CLI = client
CC = cc
CCFLAGS = -Wall -Werror -Wextra
INC_LINK = -I./inc
LIBS = -L./lib/libft -lft\

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

all : libft $(SRV) $(CLI)

$(SRV) : $(SRV_OBJS) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(SRV) $(SRV_OBJS)

$(CLI) : $(CLI_OBJS) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(CLI) $(CLI_OBJS)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

libft :
	@$(MAKE) -C ./lib/libft

clean :
	@$(MAKE) -C ./lib/libft clean
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf ./lib/ft_printf/libftprintf.a
	rm -rf $(SRV) $(CLI)

re : fclean all

.PHONY: all clean fclean
