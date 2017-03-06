# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:24:52 by bkabbas           #+#    #+#              #
#    Updated: 2016/06/28 20:23:36 by Rakiah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIMIZE = yes
PROF = no
DEBUG = no

# Paths rlists

PATH_RCONTAINERS = ../rcontainers

# Paths
PATH_HEADERS = -I includes/ -I $(PATH_RCONTAINERS)/includes/
PATH_SRC = sources/

# Debug
ifeq ($(DEBUG), yes)
	CFLAGS += -g -O0
endif

# Prof
ifeq ($(PROF), yes)
	CFLAGS += -pg
endif

# Optimization
ifeq ($(OPTIMIZE), yes)
	CFLAGS += -O3
endif

# Sources
SOURCES = $(PATH_SRC)ft_isupper.c \
		$(PATH_SRC)ft_memjoin.c \
		$(PATH_SRC)ft_strclr.c \
		$(PATH_SRC)ft_strnew.c \
		$(PATH_SRC)ft_itoa.c \
		$(PATH_SRC)ft_memmove.c \
		$(PATH_SRC)ft_strcmp.c \
		$(PATH_SRC)ft_strnstr.c \
		$(PATH_SRC)ft_memset.c \
		$(PATH_SRC)ft_strcpy.c \
		$(PATH_SRC)ft_strrchr.c \
		$(PATH_SRC)ft_atoi.c \
		$(PATH_SRC)ft_atof.c \
		$(PATH_SRC)ft_memswap.c \
		$(PATH_SRC)ft_strdel.c \
		$(PATH_SRC)ft_strrev.c \
		$(PATH_SRC)ft_bzero.c \
		$(PATH_SRC)ft_strdup.c \
		$(PATH_SRC)ft_strndup.c \
		$(PATH_SRC)ft_strsplit.c \
		$(PATH_SRC)ft_strequ.c \
		$(PATH_SRC)ft_strstr.c \
		$(PATH_SRC)ft_striter.c \
		$(PATH_SRC)ft_strsub.c \
		$(PATH_SRC)ft_putchar.c \
		$(PATH_SRC)ft_striteri.c \
		$(PATH_SRC)ft_strtolower.c \
		$(PATH_SRC)ft_putchar_fd.c \
		$(PATH_SRC)ft_strjoin.c \
		$(PATH_SRC)ft_strtoupper.c \
		$(PATH_SRC)ft_putendl.c \
		$(PATH_SRC)ft_strlcat.c \
		$(PATH_SRC)ft_strtrim.c \
		$(PATH_SRC)ft_getnextxchar.c \
		$(PATH_SRC)ft_putendl_fd.c \
		$(PATH_SRC)ft_strlcpy.c \
		$(PATH_SRC)ft_isalnum.c \
		$(PATH_SRC)ft_putnbr.c \
		$(PATH_SRC)ft_strlen.c \
		$(PATH_SRC)ft_strtrimchar.c \
		$(PATH_SRC)ft_isalpha.c \
		$(PATH_SRC)ft_memalloc.c \
		$(PATH_SRC)ft_putnbr_fd.c \
		$(PATH_SRC)ft_strmap.c \
		$(PATH_SRC)ft_strtrimlchar.c \
		$(PATH_SRC)ft_isascii.c \
		$(PATH_SRC)ft_memccpy.c \
		$(PATH_SRC)ft_putstr.c \
		$(PATH_SRC)ft_strmapi.c \
		$(PATH_SRC)ft_strtrimrchar.c \
		$(PATH_SRC)ft_isdigit.c \
		$(PATH_SRC)ft_memchr.c \
		$(PATH_SRC)ft_putstr_fd.c \
		$(PATH_SRC)ft_strncat.c \
		$(PATH_SRC)ft_tolower.c \
		$(PATH_SRC)ft_islower.c \
		$(PATH_SRC)ft_memcmp.c \
		$(PATH_SRC)ft_strcat.c \
		$(PATH_SRC)ft_strncmp.c \
		$(PATH_SRC)ft_toupper.c \
		$(PATH_SRC)ft_isprint.c \
		$(PATH_SRC)ft_memcpy.c \
		$(PATH_SRC)ft_strchr.c \
		$(PATH_SRC)ft_strncpy.c \
		$(PATH_SRC)ft_isspace.c \
		$(PATH_SRC)ft_memdel.c \
		$(PATH_SRC)ft_strchr_count.c \
		$(PATH_SRC)ft_strnequ.c \
		$(PATH_SRC)ft_strchrnul.c \
		$(PATH_SRC)ft_strnchr.c \
		$(PATH_SRC)ft_create_tab.c \
		$(PATH_SRC)ft_delete_tab.c \
		$(PATH_SRC)get_next_line.c \

# Objects
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo library linked correctly

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
