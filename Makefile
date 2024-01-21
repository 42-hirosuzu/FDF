# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 09:52:44 by hirosuzu          #+#    #+#              #
#    Updated: 2024/01/21 18:49:32 by hirosuzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRCS	=	\
affine_transformation.c	\
color.c	\
draw.c	\
error_exit.c	\
main.c	\
map_display.c	\
readmap.c	\
key_press.c	\

OBJS = $(SRCS:.c=.o)
LIBFTDIR = Libft/
LIBFTNAME = libft.a
PRINTFDIR = printf/
PRINTFNAME = libftprintf.a
LIBFT = $(LIBFTDIR)$(LIBFTNAME)
PRINTF = $(PRINTFDIR)$(PRINTFNAME)
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTNAME) $(PRINTFNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTNAME) $(PRINTFNAME) -Imlx -lmlx -framework OpenGL -framework AppKit

$(LIBFTNAME): 
	make -C $(LIBFTDIR) 
	cp $(LIBFT) ./

$(PRINTFNAME): 
	make -C $(PRINTFDIR)
	cp $(PRINTF) ./

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C $(LIBFTDIR)
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBFTNAME)
	$(RM) $(PRINTF)
	$(RM) $(PRINTFNAME)
	$(RM) $(NAME)

re: fclean all

# main:
# 	cc -g -fsanitize=address -Imlx -lmlx -framework OpenGL -framework AppKit Libft/*.c printf/*.c *.c

.PHONY: all clean fclean re


