GREEN=\033[38;5;046m
YELLOW =\033[38;5;220m
RED=\033[0;31m
BLUE=\033[0;34m
LBLUE=\033[1;36m
LPURPLE=\033[1;35m
PURPLE=\033[0;35m
CYAN="\033[38;5;51m"
NCYAN=\033[0;36m

WHITE="\033[38;5;231m

# Underline
UBlack=\033[4;30m       # Black
URed=\033[4;31m         # Red
UGreen=\033[4;32m       # Green
UYellow=\033[4;33m      # Yellow
UBlue=\033[4;34m        # Blue
UPurple=\033[4;35m      # Purple
UCyan=\033[4;36m        # Cyan
UWhite=\033[4;37m       # White

END=\033[0m

FRAME_LINE_CYAN=  "$(CYAN)***********************************************"
NEWSECTION = "$(UGreen)                                                                                       $(END)"
INTRO = "$(RED)"

NAME_BONUS = checker
NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER= push_swap.h

LIBFTPRINTF=libftprintf/libftprintf.a

src  = 		cost.c\
			do_move.c\
			init_stack.c\
			input_correct_check.c\
			main.c\
			position.c\
			push.c\
			reverse_rotate.c\
			rotate.c\
			sort_tiny.c\
			sort.c\
			stack_function.c\
			swap.c\
			utils.c\
			utils2.c\
			utils3.c\
			verif_input.c\

src_bonus  =	do_move.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			init_stack.c\
			input_correct_check.c\
			main.c\
			push.c\
			reverse_rotate.c\
			rotate.c\
			stack_function.c\
			swap.c\
			utils.c\
			utils2.c\
			utils3.c\
			verif_input.c\

SRCS = $(addprefix ./MANDATORY/, $(src))
OBJS = $(SRCS:c=o)

SRCS_BONUS = $(addprefix ./BONUS/, $(src_bonus))
OBJS_BONUS = $(SRCS_BONUS:c=o)

$(LIBFTPRINTF):
	@echo "$(FRAME_LINE_CYAN)"
	@echo "*                                             *"
	@echo "*                                             *"
	@echo "*             $(END)$(RED)M$(END)$(YELLOW)A$(END)$(GREEN)K$(END)$(LBLUE)E$(END)$(BLUE)F$(END)$(LPURPLE)I$(END)$(PURPLE)L$(END)$(RED)E$(END)$(GREEN) P$(END)$(YELLOW)R$(END)$(BLUE)E$(END)$(LBLUE)S$(END)$(PURPLE)E$(END)$(LPURPLE)N$(END)$(NCYAN)T$(END)$(LBLUE)                *"
	@echo "*                                             *"
	@echo "*                                             *"
	@echo "***********************************************$(END)"
	@echo "$(YELLOW)Building libftprintf library...$(END)"
	@echo $(NEWSECTION)
	$(MAKE) -C ./libftprintf 
	@echo $(NEWSECTION)
	@echo "$(GREEN)                        Libftprintf library built successfully!$(END)"
	@echo $(NEWSECTION)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	@echo "$(URed)                      Compiling push_swap program...                                         $(END)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)
	@echo "$(GREEN)                                push_swap program compiled!$(END)"
	@echo $(NEWSECTION)

$(NAME_BONUS): $(LIBFTPRINTF) $(OBJS_BONUS)
	@echo "$(URed)                      Compiling push_swap bonus program...                                         $(END)"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFTPRINTF) -o $(NAME_BONUS)
	@echo "$(GREEN)                                push_swap bonus program compiled!$(END)"
	@echo $(NEWSECTION)
######### RULES ########
all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@echo "$(YELLOW)Removing object files...$(END)"
	@rm -rf ./MANDATORY/*.o
	@rm -rf ./BONUS/*.o
	$(MAKE) clean -C ./libftprintf
	@echo "$(GREEN)Object files deleted!$(END)"
	@echo $(NEWSECTION)

fclean: clean
	@echo "$(YELLOW)Removing object files and program...$(END)"
	$(MAKE) fclean -C ./libftprintf
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "$(GREEN)fclean completed!$(END)"
	@echo $(NEWSECTION)
	
re: fclean all

re_bonus: fclean bonus