NAME = raytracer

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -O3
INC = -I ./objects

SRCS = main.cpp

OBJECTS_F = Sphere.cpp

SRCS+= $(addprefix objects/, $(OBJECTS_F))

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
