_YELLOW="\e[38;5;226m"
_RED="\e[38;5;9m"
_GREEN="\e[38;5;10m" 

NAME		= philo 

SRC			= parsing/check_number_of_arg.c\
			  utils_libft/function_lib.c\
			  print/print_error.c\
			  print/print_messages.c\
			  main.c\
			  clock/get_time.c\
			  routine/routine.c\
			  init_data/struct_init.c\
			  clean/clean_program.c\
			
SRCDIR 		= ./src/

INCDIR 		= ./includes/

SRCS 		= $(addprefix $(SRCDIR), $(SRC))

OBJS		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Werror -Wextra -g -pthread -I$(INCDIR) #-fsanitize=thread

CC			= gcc

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@

all :		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
			@echo $(_GREEN)
			@echo "*************************"
			@echo "*                       *"
			@echo "*  COMPILATION SUCCESS  *"
			@echo "*                       *"
			@echo "*************************"

clean_1 : 
			@echo $(_YELLOW)
			@echo "*************************"
			@echo "*                       *"
			@echo "*    CLEAN  COMPLETE    *"
			@echo "*                       *"
			@echo "*************************"

clean : 	clean_1
			@rm -f $(OBJS)
fclean_1 :
			@echo $(_RED)
			@echo "*************************"
			@echo "*                       *"
			@echo "*    FCLEAN COMPLETE    *"
			@echo "*                       *"
			@echo "*************************"

fclean : 	clean fclean_1
			@rm -f $(NAME)
	
re : 		fclean all 

.PHONY: all clean fclean re
