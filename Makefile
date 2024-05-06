NAME 	= so_long
CFLAGS 	= -Wextra -Wall -Werror
LIBMLX	= MLX42
LIBFTDIR = ./libft
HEADERS	= -I ./includes
MLX_A 	= MLX42/build/libmlx42.a
LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFT	= ./libft/libft.a
SRCS	= srcs/so_long.c \
        srcs/check_map.c \
        srcs/error_handling.c \
        srcs/check_items.c \
        srcs/check_path.c \
		srcs/init_game.c \
		srcs/game_utils.c \
		srcs/movements.c

OBJS	= ${SRCS:.c=.o}
MAKE    = make
CMAKE   = cmake

all: $(NAME)

libmlx: $(MLX_A)

$(MLX_A): $(LIBMLX)/build
	 @$(MAKE) -C $(LIBMLX)/build -j4

$(LIBMLX)/build: 
	@$(CMAKE) $(LIBMLX) -B $(LIBMLX)/build

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

libft:
	@$(MAKE) all -C $(LIBFTDIR)

$(NAME): $(OBJS) $(MLX_A) libft
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -f  libft.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx