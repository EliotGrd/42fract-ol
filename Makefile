
NAME = fractol

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	MLX_PATH = minilibx_opengl_20191021/
	MLX_AR = $(MLX_PATH)libmlx.a
	MLXFLAGS = -framework OpenGL -framework AppKit
	KEY_HEADER = ../includes/keys_mac.h
else  # Linux
	MLX_PATH = minilibx-linux/
	MLX_AR = $(MLX_PATH)libmlx.a
	MLXFLAGS = -Lmlx_linux -lXext -lX11 -lm -lz
	KEY_HEADER = ../includes/keys_linux.h
endif

SRC_PATH = srcs/
OBJ_PATH = objs/
LIBFT_PATH = libft/
LIBFT_AR = $(LIBFT_PATH)libft.a

SRC = color.c color_update.c handle_keys.c mathing.c render.c main.c exit.c init.c fractals.c 
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -Iincludes -I$(LIBFT_PATH) -I$(MLX_PATH)

PURPLE = \033[0;35m
NC = \033[0m

all: $(MLX_AR) $(LIBFT_AR) $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(PURPLE)  Compiling Fractol...$(NC)"
	@$(CC) $(CFLAGS) -DKEY_HEADER='"$(KEY_HEADER)"' $(OBJS) $(MLX_AR) $(LIBFT_AR) $(INC) $(MLXFLAGS) -o $(NAME)
	@echo "\n$(PURPLE)  Ready ✓$(NC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -DKEY_HEADER='"$(KEY_HEADER)"' $(INC) -c $< -o $@

$(MLX_AR):
	@echo "\n$(PURPLE)  Compiling MLX... $(NC)"
	@make -s -C $(MLX_PATH)
	@echo "\n$(PURPLE)  Done ✓ $(NC)"

$(LIBFT_AR):
	@echo "\n$(PURPLE)  Compiling LIBFT...$(NC)"
	@make -s -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

clean:
	@echo "\n$(PURPLE)  Cleaning object files... $(NC)"
	@rm -rf $(OBJ_PATH)
	@make -s clean -C $(LIBFT_PATH)
	@make -s clean -C $(MLX_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

fclean: clean
	@echo "\n$(PURPLE)  Cleaning Fractol...$(NC)"
	@$(RM) $(NAME)
	@make -s fclean -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

$(OBJS) : $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re
