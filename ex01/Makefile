# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 14:14:09 by yuliaboktae       #+#    #+#              #
#    Updated: 2023/12/08 19:06:11 by yuboktae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

SRC_FILES	= main.cpp Serializer.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

RM = rm -f
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -I/usr/local/include -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re