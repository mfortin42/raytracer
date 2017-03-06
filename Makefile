# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/21 15:25:27 by Rakiah            #+#    #+#              #
#    Updated: 2016/06/30 16:54:50 by bkabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = raytracer
CFLAGS = -Wall -Wextra -Werror
CLIBS = -l ft -l rcontainers -l rmath -l m -l SDL2_ttf -l SDL2 -l pthread

PATH_RCONTAINERS = libs/rcontainers
PATH_RMATH = libs/rmath
PATH_FT = libs/libft
PATH_SDL = ~/.brew/lib
PATH_SRC = sources/

OPTIMIZE = yes
DEBUG = no

ifeq ($(OPTIMIZE), yes)
	CFLAGS += -O3
endif

ifeq ($(DEBUG), yes)
	CFLAGS += -O0 -g
endif


CLIBS_PATH += -L $(PATH_RCONTAINERS)/
CLIBS_PATH += -L $(PATH_RMATH)/
CLIBS_PATH += -L $(PATH_FT)/
CLIBS_PATH += -L $(PATH_SDL)/

PATH_HEADERS += -I includes/
PATH_HEADERS += -I $(PATH_FT)/includes/
PATH_HEADERS += -I $(PATH_RCONTAINERS)/includes/
PATH_HEADERS += -I $(PATH_RMATH)/includes/
PATH_HEADERS += -I libs/SDL2/includes/

SRC += $(PATH_SRC)main.c
SRC += $(PATH_SRC)core_methods.c
SRC += $(PATH_SRC)texture.c
SRC += $(PATH_SRC)rasterizer.c
SRC += $(PATH_SRC)rasterizer2.c
SRC += $(PATH_SRC)ray.c
SRC += $(PATH_SRC)camera.c
SRC += $(PATH_SRC)light.c
SRC += $(PATH_SRC)cone.c
SRC += $(PATH_SRC)sphere.c
SRC += $(PATH_SRC)plane.c
SRC += $(PATH_SRC)cylinder.c
SRC += $(PATH_SRC)disk.c
SRC += $(PATH_SRC)formula.c
SRC += $(PATH_SRC)parser.c
SRC += $(PATH_SRC)parse_camera.c
SRC += $(PATH_SRC)parse_texture.c
SRC += $(PATH_SRC)parse_material.c
SRC += $(PATH_SRC)parse_material_2.c
SRC += $(PATH_SRC)parse_material_3.c
SRC += $(PATH_SRC)parse_object.c
SRC += $(PATH_SRC)parse_object_2.c
SRC += $(PATH_SRC)parse_light.c
SRC += $(PATH_SRC)parse_light_2.c
SRC += $(PATH_SRC)parse_utilities.c
SRC += $(PATH_SRC)utilities.c
SRC += $(PATH_SRC)screenshot.c
SRC += $(PATH_SRC)key_down.c
SRC += $(PATH_SRC)key_up.c
SRC += $(PATH_SRC)mouse_up.c
SRC += $(PATH_SRC)mouse_down.c
SRC += $(PATH_SRC)mouse_motion.c
SRC += $(PATH_SRC)mouse_pos.c
SRC += $(PATH_SRC)ui_element.c
SRC += $(PATH_SRC)interface.c
SRC += $(PATH_SRC)element_hooks.c
SRC += $(PATH_SRC)keycode_converter.c
SRC += $(PATH_SRC)button_hooks.c
SRC += $(PATH_SRC)label.c
SRC += $(PATH_SRC)progress_bar.c
SRC += $(PATH_SRC)reflection_refraction.c
SRC += $(PATH_SRC)multithread.c
SRC += $(PATH_SRC)post_effects.c
SRC += $(PATH_SRC)blurr.c
SRC += $(PATH_SRC)releaser.c
SRC += $(PATH_SRC)interface_post_effects.c
SRC += $(PATH_SRC)interface_aliasing.c
SRC += $(PATH_SRC)interface_helper.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PATH_FT)/
	make -C $(PATH_RCONTAINERS)/
	make -C $(PATH_RMATH)/
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(PATH_HEADERS) -o $@ -c $<

nolib: $(NAME)
	$(CC) $(CFLAGS) $(CLIBS_PATH) -o $(NAME) $(OBJ) $(CLIBS)

clean:
	@rm -f $(OBJ)
	make -C $(PATH_FT)/ clean
	make -C $(PATH_RCONTAINERS)/ clean
	make -C $(PATH_RMATH)/ clean
	@echo removed binary files

fclean: clean
	@rm -f $(NAME)
	make -C $(PATH_FT)/ fclean
	make -C $(PATH_RCONTAINERS)/ fclean
	make -C $(PATH_RMATH)/ fclean
	@echo removed library

re: fclean all

.PHONY: all clean fclean re nolib
