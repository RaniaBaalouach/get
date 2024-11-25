CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = getnextline.a
HEADER = get_next_line.h
RM = rm -rf
AR = ar -rcs

SRC =	get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
