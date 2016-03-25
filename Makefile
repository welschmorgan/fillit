NAME=fillit

LIBFT_DIR = ../libft
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

SRCS = $(shell find srcs -name "*.c" -type f)
OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
INCS = -I$(INC_DIR) -I$(LIBFT_DIR)/includes

CC = gcc
LD = $(CC)

CFLAGS = -Wall -Werror -Wextra $(INCS)
LDFLAGS = -L$(LIBFT_DIR) -lft

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(LD) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if [ ! -e $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT_DIR)/libft.a:
	make libft.a -C $(LIBFT_DIR)

all: lib $(NAME)

lib: $(LIBFT_DIR)/libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re run clean fclean lib
