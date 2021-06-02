# -*- Makefile -*-

SRCS		=	$(wildcard ./*.c)

OBJS		=	$(SRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
AR			=	ar rsc
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:	clean fclean re all

# to make the libft.a we'll need the .o files, so we need to compile the .c files with the -c flag
# theres no need to include header files in compiling
# we then proceed to create the static library with the ar rsc command

# re is to fclean first and make all next
# since .c=.o converts the files, we don't need the gcc -c to create the .o files