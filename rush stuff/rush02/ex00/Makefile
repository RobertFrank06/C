CFLAGS += -Wall -Wextra -Werror
NAME = rush-02
SOURCES = 	main.c \
			parse_dictionary.c \
			num_conversion.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)