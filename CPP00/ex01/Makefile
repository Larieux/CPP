# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:18:32 by mlarieux          #+#    #+#              #
#    Updated: 2025/01/23 13:10:14 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		Contact.cpp \
			PhoneBook.cpp \
			Main.cpp

SRCDIR =	src
INCDIR =	include
OBJDIR =	obj
BINDIR =	.

VPATH = $(SRCDIR)

OBJ := $(SRC:%.cpp=$(OBJDIR)/%.o)

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
CPPFLAGS =	-I$(INCDIR)

NAME =	$(BINDIR)/phonebook

all : $(NAME)

$(NAME) : $(OBJ) | $(BINDIR)
	$(CC) $(CPPFLAGS) $^ -o $@ $(CXXFLAGS)

$(BINDIR) $(OBJDIR) :
	mkdir $@

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) -rv $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re
