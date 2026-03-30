
HEADERS = ./push_swap.h
NAME = push_swap
FLAGS = -Wall -Werror -Wextra
C = convert_input.c \
	error_verif.c \
	find_median.c \
	main_algo.c \
	main_algo2.c \
	move_to_place.c \
	push_swap_utils.c \
	push_swap.c \
	size2_algo.c \
	size3_algo.c \
	size4_algo.c \
	size5_algo.c \
	size2_helper.c \
	test_output.c \
	libft.a

$(NAME): 
	cc $(FLAGS) -o push_swap -I $(HEADERS) $(C)

all: $(NAME)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
