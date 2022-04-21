#NAMES
NAME		= push_swap
NAME_BON	= checker

#COMP
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

#LIBFT
LIBFT_DIR	= lib
LIBFT_MAKE	= cd $(LIBFT_DIR) && make all && make bonus
LIBFT_INC	= -L $(LIBFT_DIR) -lft


#SRC
SRC_DIR		= src
SRC			= src/main.c \
			src/exit.c \
			src/parser.c \
			src/utils.c \
			src/quick_sort.c \
			src/algorithm.c\
			src/list_utils.c \
			src/swap.c \
			src/push.c \
			src/rotate.c \
			src/reverse_rotate.c \
			src/if_sorted.c \
			src/scoring.c \
			src/rotate_opt.c \
			src/move.c \
			src/extra_funks.c \

SRC_BON_DIR		= src_bonus
SRC_BON			= src_bonus/main_bonus.c \
			src_bonus/exit_bonus.c \
			src_bonus/parser_bonus.c \
			src_bonus/utils_bonus.c \
			src_bonus/algorithm_bonus.c\
			src_bonus/list_utils_bonus.c \
			src_bonus/swap_bonus.c \
			src_bonus/push_bonus.c \
			src_bonus/rotate_bonus.c \
			src_bonus/reverse_rotate_bonus.c \
			src_bonus/if_sorted_bonus.c \
			src_bonus/extra_funks_bonus.c \
			src_bonus/get_next_line_bonus.c \
			src_bonus/get_next_line_utils_bonus.c \

#INC
INC_DIR		= inc
INC			= $(INC_DIR)/push_swap.h

INC_BON_DIR		= inc_bonus
INC_BON			= $(INC_BON_DIR)/push_swap_bonus.h

#OBJ
OBJ_DIR		= obj
OBJ			= $(patsubst src%, $(OBJ_DIR)%, $(SRC:.c=.o))

OBJ_BON_DIR		= obj_bonus
OBJ_BON			= $(patsubst src_bonus%, $(OBJ_BON_DIR)%, $(SRC_BON:.c=.o))

#RMS
RM_DIR		= rm -rf
RM_FILE		= rm -f

#DEPS
$(NAME): $(OBJ) $(INC)
	$(LIBFT_MAKE)
	$(CC) $(OBJ) $(LIBFT_INC) -o $(NAME)

$(NAME_BON): $(OBJ_BON) $(INC_BON)
	$(LIBFT_MAKE)
	$(CC) $(OBJ_BON) $(LIBFT_INC) -o $(NAME_BON)

#OBJ DEPS
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(OBJ): $(INC)	| $(OBJ_DIR)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)


$(OBJ_BON_DIR)/%.o: src_bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_BON)

$(OBJ_BON): $(INC_BON)	| $(OBJ_BON_DIR)

$(OBJ_BON_DIR):
			mkdir -p $(OBJ_BON_DIR)


#RULES
all:	$(NAME)	bonus

bonus: $(NAME_BON)


clean:
		${RM_DIR} ${OBJ_DIR}
		${RM_DIR} ${OBJ_BON_DIR}
		cd $(LIBFT_DIR) && make clean


fclean:	clean
		${RM_FILE} $(NAME)
		${RM_FILE} $(NAME_BON)
		cd $(LIBFT_DIR) && make fclean

re:		fclean all

#OTHER
.PHONY: all clean fclean re bonus
