#          ----------========== {     VARS     } ==========----------

NAME = push_swap
BONUS_NAME = checker
RMF = rm -f
RMD = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3
HDDIR = -I includes
LIB = libft/libft.a

#          ----------========== {     SRCS     } ==========----------

MANDATORY_SRCS =	chunks_pivots.c \
					errors.c \
					find_place.c \
					ft_free.c \
					get_cheapest_rot.c \
					get_cheapest.c \
					get_datas.c \
					init_piles.c \
					int_tab.c \
					main.c \
					movesa.c \
					movesb.c \
					movesab.c \
					min_max.c \
					push_all_b.c \
					push_swap.c \
					push_to_a.c \
					sort_three.c \
					utils.c

BONUS_SRCS = 		checker_gnl_bonus.c \
					errors_bonus.c \
					exec_bonus.c \
					ft_free_bonus.c \
					get_datas_bonus.c \
					main_bonus.c \
					movesa_bonus.c \
					movesab_bonus.c \
					movesb_bonus.c \
					utils_bonus.c

#          ----------========== {     OBJS     } ==========----------

SRCS_DIR = mandatory/
OBJS_DIR = mandatory_objs/
SRCS_BONUS_DIR = bonus/
OBJS_BONUS_DIR = bonus_objs/

OBJS = $(addprefix $(OBJS_DIR), $(MANDATORY_SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(BONUS_SRCS:.c=.o))

VPATH = $(shell find $(SRCS_DIR) $(SRCS_BONUS_DIR) -type d)

#           ----------========== {    REGLES    } ==========----------

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@
	@printf "\n$(GREEN)$(NAME) created!$(DEFAULT)\n"	

$(BONUS_NAME): $(OBJS_BONUS_DIR) $(OBJS_BONUS)
	@$(MAKE) -C libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $@ -g
	@printf "\n$(GREEN)$(BONUS_NAME) created!$(DEFAULT)\n"

$(OBJS_DIR)%.o:%.c
	@$(CC) $(CFLAGS) $(HDDIR) -c $< -o $@ 
	@printf "$(GREEN).$(DEFAULT)"

$(OBJS_BONUS_DIR)%.o:%.c
	@$(CC) $(CFLAGS) $(HDDIR) -c $< -o $@ 
	@printf "$(GREEN).$(DEFAULT)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	@mkdir -p $(OBJS_BONUS_DIR)

clean:
	@$(MAKE) -C libft clean --no-print-directory
	@$(RMF) $(OBJS) $(OBJS_BONUS)
	@$(RMD) $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@printf "$(YELLOW)object files for push_swap deleted!$(DEFAULT)\n"


fclean: 
	@$(MAKE) clean --no-print-directory
	@$(MAKE) -C libft fclean --no-print-directory
	@$(RMF) $(NAME) $(BONUS_NAME)
	@printf "$(RED)$(NAME) deleted!$(DEFAULT)\n"

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus lib_compile clean fclean re

#           ----------========== {    COLORS    } ==========----------

RED = \033[1;31m
GREEN = \033[1;32m
GREEN_BG = \033[1;42m
YELLOW = \033[1;33m
DEFAULT = \033[0m
