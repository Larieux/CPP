# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 16:04:16 by mlarieux          #+#    #+#              #
#    Updated: 2025/01/23 13:03:45 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = megaphone.cpp

SRC_DIR =	src
OBJ_DIR =	obj
BIN_DIR =	.

VPATH = $(SRC_DIR)

OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

NAME =	$(BIN_DIR)/megaphone

all : $(NAME)

$(NAME) : $(OBJ) | $(BIN_DIR)
	$(CC) $^ -o $@ $(CXXFLAGS)

$(BIN_DIR) ${OBJ_DIR} :
	mkdir $@

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) -rv $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re
