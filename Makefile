NAME = libft
FLAGS = -Wall -Werror -Wextra
SRCS = \
ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
ft_isdigit.c	ft_isprint.c	ft_memcpy.c		ft_memmove.c	\
ft_memset.c		ft_strlcpy.c	ft_strlen.c		ft_toupper.c	\
ft_tolower.c	ft_strchr.c		ft_strrchr.c	ft_strncmp.c	\
ft_memchr.c		ft_strlcat.c	ft_memcmp.c		ft_strnstr.c	\
ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		\
ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
ft_putendl_fd.c	ft_putnbr_fd.c
OBJS = \
ft_bzero.o		ft_isalnum.o	ft_isalpha.o	ft_isascii.o	\
ft_isdigit.o	ft_isprint.o	ft_memcpy.o		ft_memmove.o	\
ft_memset.o		ft_strlcpy.o	ft_strlen.o		ft_toupper.o	\
ft_tolower.o	ft_strchr.o		ft_strrchr.o	ft_strncmp.o	\
ft_memchr.o		ft_strlcat.o	ft_memcmp.o		ft_strnstr.o	\
ft_atoi.o		ft_calloc.o		ft_strdup.o		ft_substr.o		\
ft_strjoin.o	ft_strtrim.o	ft_split.o		ft_itoa.o		\
ft_strmapi.o	ft_striteri.o	ft_putchar_fd.o	ft_putstr_fd.o	\
ft_putendl_fd.o	ft_putnbr_fd.o
BNS_SRCS = \
ft_lstnew_bonus.c
BNS_OBJS = \
ft_lstnew_bonus.o

all: $(NAME)

$(NAME): $(SRCS)
	cc $(FLAGS) -c $(SRCS)
	ar rc $(NAME).a $(OBJS)
	ranlib  $(NAME).a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME).a

re: fclean all

bonus: $(BNS_SRCS)
	cc $(FLAGS) -c $(BNS_SRCS)
	ar rc $(NAME).a $(BNS_OBJS)
	ranlib  $(NAME).a

so:
	gcc $(FLAGS) -c $(SRCS) $(BNS_SRCS)
	gcc -shared -o libft.so $(OBJS) $(BNS_OBJS)
