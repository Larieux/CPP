SRC=megaphone.cpp

SRCDIR =	src
INCDIR =	include
OBJDIR =	obj
BINDIR =	.

VPATH =	$(SRCDIR)

OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98
CPPFLAGS =	-I$(INCDIR)

NAME =	$(BINDIR)/megaphone

all = $(NAME)

$(NAME) : $(OBJ) | $(BINDIR)
	$(CC) $^ -o $@ $(CXXFLAGS)

$(BINDIR) $(OBJDIR) :
	mkdir $@

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) -RV $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re
