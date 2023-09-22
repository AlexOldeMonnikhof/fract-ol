NAME	= fractol
CFLAGS	= -Wunreachable-code -Ofast -Wall -Wextra -Werror
LIBMLX	= ./MLX42

# -Wall -Wextra -Werror

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= main.c utils.c fractals.c check.c init.c hooks.c color.c text.c
# OBJ		:= ${SRCS:.c=.o}
OBJS	= $(addprefix obj/, ${SRCS:.c=.o})

all: libmlx obj/ $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

obj/%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx