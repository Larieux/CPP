# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:18:32 by mlarieux          #+#    #+#              #
#    Updated: 2024/12/11 17:29:06 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		phonebook.cpp

SRCDIR =	src
INCDIR =	include
OBJDIR =	obj
BINDIR =	.

VPATH = $(SRCDIR)

OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
CPPFLAGS =	-I$(INCDIR)

NAME =	$(BINDIR)/phonebook

all : $(NAME)

$(NAME) : $(OBJ) | $(BINDIR)
	$(CC) $(CPPFLAGS) $^ -o $@ $(CXXFLAGS)

$(BINDIR) $(OBJDIR) :
	mkdir $@

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) -rv $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re