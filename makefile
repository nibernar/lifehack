NAME			=	lifeHack

HEADERS_FILES	=	Map_parsing.hpp \
					Map.hpp \
					Node.hpp

HEADERS			= $(HEADERS_FILES)

SRC_FILES		=	main.cpp \
					Map_parsing.cpp \
					Map.cpp \
					Node.cpp

SRCS			= 	$(SRC_FILES)

BUILD_DIR		=	build
OBJS			=	$(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)

CC				=	c++
CC_FLAGS		=	-Wextra -Werror -Wall
LDFLAGS 		=	-lglfw -lGL -lm -lpthread -ldl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re% 