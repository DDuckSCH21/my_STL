SRCS		=	main.cpp test_stack.cpp test_vector.cpp test_map.cpp

OBJS		=	$(SRCS:.cpp=.o)

HDRS		=	vector.hpp iterator.hpp stack.hpp map.hpp \
				algorithm.hpp functional.hpp utliuty.hpp	\
				tree.hpp test.hpp

FLAG		=	-Wall -Wextra -Werror -std=c++98 -g

CXX			=	clang++

DEF			=	NAME_SPACE=std

CXXDEF		=	clang++ -D $(DEF)

%.o:%.cpp		$(HDRS)
				$(CXX) $(FLAG) -c $< -o $@

NAME		=	ft_containers

RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(FLAG) -o $(NAME) $(OBJS)

std:		fclean
			clang++ -D NAME_SPACE=std -D KEK=22 main.cpp test_map.cpp test_vector.cpp test_stack.cpp -o ft_containers

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re