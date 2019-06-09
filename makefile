NAME = ft_retro
PPFLAG = -Wall -Wextra -Werror -lncurses
COMP = g++ $(PPFLAG)
FILE = main.cpp

all : $(NAME)

$(NAME) :
	@$(COMP) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all
