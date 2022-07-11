# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 20:09:27 by hyna              #+#    #+#              #
#    Updated: 2022/07/11 12:12:12 by hyna             ###   ########.fr        #
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
				srv_utils.c\

CLI_SRCS_NAME = cli_main.c\
				cli_transmitter.c\
				cli_utils.c\

SRCS_PATH = ./srcs
SRV_SRCS = $(addprefix $(SRCS_PATH)/, $(SRV_SRCS_NAME))
CLI_SRCS = $(addprefix $(SRCS_PATH)/, $(CLI_SRCS_NAME))

SRV_SRCS_BONUS = $(SRV_SRCS:.c=_bonus.c)
CLI_SRCS_BONUS = $(CLI_SRCS:.c=_bonus.c)

SRV_OBJS_NAME = $(SRV_SRCS_NAME:.c=.o)
CLI_OBJS_NAME = $(CLI_SRCS_NAME:.c=.o)

OBJS_PATH = ./objs
SRV_OBJS = $(addprefix $(OBJS_PATH)/, $(SRV_OBJS_NAME))
CLI_OBJS = $(addprefix $(OBJS_PATH)/, $(CLI_OBJS_NAME))

SRV_OBJS_BONUS = $(SRV_OBJS:.o=_bonus.o)
CLI_OBJS_BONUS = $(CLI_OBJS:.o=_bonus.o)

ifdef BONUS_
	SRV_O = $(SRV_OBJS_BONUS)
	CLI_O = $(CLI_OBJS_BONUS)
else
	SRV_O = $(SRV_OBJS)
	CLI_O = $(CLI_OBJS)
endif

all : ft_printf $(NAME) $(NAME2)

$(NAME) : $(SRV_O) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(NAME) $(SRV_O)

$(NAME2) : $(CLI_O) 
	$(CC) $(CCFLAGS) $(LIBS) -o $(NAME2) $(CLI_O)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

bonus :
	@$(MAKE) BONUS_=1 all

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
