# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 16:03:57 by mlarieux          #+#    #+#              #
#    Updated: 2025/03/20 13:34:03 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \
		main.cpp

SRCDIR =	src
INCDIR =	include
OBJDIR =	obj
BINDIR =	.

VPATH =	$(SRCDIR)

OBJ := $(SRC:%.cpp=$(OBJDIR)/%.o)

CXX =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -g
CPPFLAGS =	-I$(INCDIR)

NAME =	$(BINDIR)/unnessary_violence

all : $(NAME)

$(NAME) : $(OBJ) | $(BINDIR)
	$(CXX) $(CPPFLAGS) $^ -o $@ $(CXXFLAGS)

$(BINDIR) $(OBJDIR) :
	mkdir $@

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@ $(CXXFLAGS)

clean :
	@$(RM) -rv $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re
