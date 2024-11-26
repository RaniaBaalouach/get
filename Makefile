CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = getnextline.a
HEADER = get_next_line.h
RM = rm -rf
AR = ar -rcs

SRC =	get_next_line.c get_next_line_utils.c
BSRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	
bonus: $(BOBJ) .bonus

.bonus: $(BOBJ)
	ar -rcs $(NAME) $(BOBJ)
	touch .bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ) $(BOBJ) .bonus 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
