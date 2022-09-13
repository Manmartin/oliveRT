NAME = raytracer

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -O3
INC = -I . -I ./scene -I ./objects

SRCS = main.cpp

OBJECTS_F 	= 	Sphere.cpp \
				Plane.cpp \
				Triangle.cpp

SCENE_F 	= 	Scene.cpp \
				render.cpp

IMAGES_F    = 	toppm.cpp


SRCS+= $(addprefix objects/, $(OBJECTS_F))
SRCS+= $(addprefix scene/, $(SCENE_F))
SRCS+= $(addprefix images/, $(IMAGES_F))

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

.PHONY: all clean fclean re
