# -*- Makefile -*-

SOURCES = $(wildcard ./srcs/*.c)

OBJS = $(SOURCES:%.c=%.o)

NAME = libftprintf.a

LIBFT = libft.a

INCLUDES = -I includes

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcsv
RM = rm -rf

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar -xv $(LIBFT)
	$(AR) $(NAME) *.o $(OBJS)

$(LIBFT): 
	make -C libft
	mv -v libft/libft.a ./libft.a

bonus: all

clean:
	$(RM) $(OBJS)
	$(RM) $(MAIN_OBJ)
	$(RM) ./*.o
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(EXEC)
	make fclean -C ./libft
	$(RM) ./__.SYMDEF\ SORTED

re: fclean all

.PHONY: all clean fclean re out