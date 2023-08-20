#          ----------========== {     VARS     } ==========----------

NAME = push_swap
BONUS_NAME = checker
RMF = rm -f
RMD = rm -rf
CFLAGS = -Wall -Wextra -Werror
HDDIR = -I includes
LIB = libft/libft.a

#          ----------========== {     SRCS     } ==========----------

MANDATORY_SRCS =	errors.c \
					ft_free.c \
					get_datas.c \
					main.c \
					min_max.c \
					push_swap.c \
					utils.c

BONUS_SRCS = 		exec_bonus.c \
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

#VPATH = $(shell find $(SRCS_DIR) -type d)
#VPATH += $(shell find $(SRCS_BONUS_DIR) -type d)

#MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)


#           ----------========== {    REGLES    } ==========----------

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -C libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@ -g
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
	@$(RMF) $(OBJS)
	@$(RMD) $(OBJS_DIR)
	@printf "$(YELLOW)object files for push_swap deleted!$(DEFAULT)\n"


fclean: 
	@$(MAKE) clean --no-print-directory
	@$(MAKE) -C libft fclean --no-print-directory
	@$(RMF) $(NAME)
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
