#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 18:52:41 by mdamesto          #+#    #+#              #
#    Updated: 2016/02/14 16:31:29 by mdamesto         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = malloc

SRC_NAME = main.c map.c block.c size.c
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/

LIB_PATH = libft
LIB_NAMES = -lft
INC_PATH = inc/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIB) $(LIB_NAMES)
CC = gcc



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) -lncurses $^ -o $@ $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette ../inc/corewar.h

.PHONY: all clean fclean re norme
.NOTPARALLEL: re