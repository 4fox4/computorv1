SRC =		computorv1.c \
			ft_abc.c \
			ft_delta.c \
			ft_error.c \
			ft_init.c \
			ft_parse.c \
			ft_parse_nb2.c \
			ft_power.c \
			ft_premier_deg.c \
			ft_print_2nd_deg.c \
			ft_second_deg.c \
			ft_sqrt.c \
			ft_str_match.c \
			polynome.c \
			power_top.c \
			ft_print_sol.c \
			ft_print_1st_deg.c \
			list_power.c \
			last_list.c \
			equal.c \
			ft_print_no_deg.c \

OBJ =		computorv1.o \
			ft_abc.o \
			ft_delta.o \
			ft_error.o \
			ft_init.o \
			ft_parse.o \
			ft_parse_nb2.o \
			ft_power.o \
			ft_premier_deg.o \
			ft_print_2nd_deg.o \
			ft_second_deg.o \
			ft_sqrt.o \
			ft_str_match.o \
			polynome.o \
			power_top.o \
			ft_print_sol.o \
			ft_print_1st_deg.o \
			list_power.o \
			last_list.o \
			equal.o \
			ft_print_no_deg.o \

LIB =		libft/libft.a

INC =		libft/includes/

FLAG =		-Wall -Wextra -Werror

NAME =		computorv1

all:		libft.a $(NAME)

$(NAME):	$(OBJ)
			gcc -g $(FLAG) -c $(SRC) -I $(INC)
			gcc -o $(NAME) $(OBJ) -L. $(LIB)

libft.a:
			make -C libft/

clean:
			rm -f $(OBJ)
			make -C libft/ clean

fclean:		clean
			rm -f $(NAME)
			make -C libft/ fclean

re:			fclean all