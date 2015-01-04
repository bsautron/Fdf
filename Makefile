CC = gcc
SRC = main.c \
	  ft_gettab.c \
	  expose_hook.c \
	  key_hook.c \
	  \
	  ft_abs.c \
	  \
	  ft_draw_line_in_image.c \
	  ft_proj_iso.c \
	  ft_proj_tab_iso.c \
	  ft_regu_tab.c \
	  ft_zoom_tab.c \
	  ft_make_draw.c \
	  ft_printtab.c
OBJ = $(SRC:.c=.o)
NAME = fdf
FLAGS = -Wall -Wextra -Werror
LX11 = -L/usr/X11/lib -lmlx -lXext -lX11
LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(FLAGS) -I libft/includes/ -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LX11)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~

re: fclean all