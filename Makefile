NAME = spring_challenge_2025

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = \
	apply_capture.c \
	board_is_solved.c \
	check_captures.c \
	debug.c \
	get_hash.c \
	init_and_copy_board.c \
	init_capture_1.c \
	init_capture_2.c \
	init_capture_3.c \
	init_capture_4.c \
	solve_board.c \
	spring_challenge_2025.c \

OBJS = $(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
