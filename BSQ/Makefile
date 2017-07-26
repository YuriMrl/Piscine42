# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btheuril <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 07:11:45 by btheuril          #+#    #+#              #
#    Updated: 2017/07/26 07:11:47 by btheuril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq
SRC_DIR		=	src
INCLUDE_DIR	=	include
OBJECT_DIR	=	obj
CC			=	gcc
C_FLAGS		=	-I$(INCLUDE_DIR) -Wall -Wextra -Werror

HEADERS		:=	bsq.h

HDRS		=	$(patsubst %,$(INCLUDE_DIR)/%,$(HEADERS))

OBJECTS 	:= 	main.o \
				bsq.o \
				utils.o \
				compute.o \
				error.o

OBJS		=	$(patsubst %,$(OBJECT_DIR)/%,$(OBJECTS))

all: $(NAME)

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c		
				$(CC) -c -o $@ $< $(C_FLAGS)

$(OBJECT_DIR):
				mkdir -p $(OBJECT_DIR)

$(NAME): $(OBJECT_DIR) $(OBJS) $(HDRS)
				$(CC) $(OBJS) -o $(NAME)

clean:
				rm -rf $(OBJECT_DIR)

fclean:	clean
				rm -rf $(NAME)

re:		fclean all
