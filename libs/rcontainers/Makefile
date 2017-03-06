# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 21:24:52 by bkabbas           #+#    #+#              #
#    Updated: 2016/06/28 20:20:45 by Rakiah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = librcontainers.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OPTIMIZE = yes
PROF = no
DEBUG = no

# Paths
PATH_HEADERS = includes
PATH_SRC = sources
PATH_SUB = lists arrays
PATH_OBJ = objects

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

CFLAGS += -I

# Sources
vpath %.c $(addprefix $(PATH_SRC)/,$(PATH_SUB))

LISTS	+=	lists_inits.c
LISTS	+=	lists_finds.c
LISTS	+=	lists_removes.c
LISTS	+=	lists_converters.c
LISTS	+=	lists_iterators.c
LISTS	+=	lists_removes_functors.c
LISTS	+=	lists_process_functors.c
LISTS	+=	lists_functors.c

ARRAYS	+=	arrays_inits.c

SOURCES +=	$(LISTS)
SOURCES +=	$(ARRAYS)

# Headers
HEADERS = $(addprefix $(PATH_HEADERS)/, $(INCLUDES))

INCLUDES += rcontainers_lists.h
INCLUDES += rcontainers_arrays.h
INCLUDES += rcontainers_structs.h
INCLUDES += rcontainers_typedefs.h

# Objects
OBJECTS += $(addprefix $(PATH_OBJ)/, $(LISTS:%.c=%.o))
OBJECTS += $(addprefix $(PATH_OBJ)/, $(ARRAYS:%.c=%.o))

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo library linked correctly

$(OBJECTS): $(HEADERS) | $(PATH_OBJ)
$(OBJECTS): $(PATH_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

$(PATH_OBJ):
	@-mkdir -p $@


clean:
	@rm -rf $(PATH_OBJ)
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	@echo removed library

re: fclean all

.PHONY: all clean fclean re
