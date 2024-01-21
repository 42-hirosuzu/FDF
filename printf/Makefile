NAME	=	libftprintf.a

SRCS	=	\
ft_printf.c \
ft_flagchar.c \
ft_flagstr.c \
ft_flagint.c \
ft_flagpoint.c \
ft_flagu.c \
ft_xbase.c \
pf_putchar_fd.c \
pf_putstr_fd.c \
pf_strlen.c \

OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -rf

all:	$(NAME)
$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
fclean:	clean
		$(RM) $(NAME)
re:	fclean all
