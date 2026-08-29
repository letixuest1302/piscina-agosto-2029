NAME		= rush-02

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.

SRCS		= main.c \
			  ft_str.c \
			  ft_trim.c \
			  file_oi.c \
			  dict.c \
			  convert.c \
			  convert_group.c \
			  convert_utils.c

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
