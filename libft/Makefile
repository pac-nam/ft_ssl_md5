# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:34:52 by tbleuse           #+#    #+#              #
#    Updated: 2018/10/23 13:48:46 by tbleuse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = srcs

INCLUDE_FOLDER = includes

OBJ_FOLDER = objs

CONV_FOLDER = conversion
CONV_NAME	=	ft_atoi.c				\
				ft_atoll.c				\
				ft_itoa.c				\
				ft_itoa_base.c			\
				ft_lltoa.c              \
				ft_ulltoa_base.c        \
				ft_wc_convert.c			\
				ft_wcs_convert.c		\
				ft_conv_utf8.c			\
				ft_intlen_base.c		\
				ft_intlen.c				\
				ft_lllen.c				\
				ft_dtoa.c				\
				ft_itoa_no_malloc.c		\
				ft_utoa_base_no_malloc.c	\

CHAR_FOLDER = char
CHAR_NAME	=	ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isdigit.c			\
				ft_isxdigit.c			\
				ft_ispunct.c			\
				ft_iscntrl.c			\
				ft_isspace.c			\
				ft_isprint.c			\
				ft_tolower.c			\
				ft_toupper.c			\
				ft_charcatindex.c		\

MEMORY_FOLDER = memory
MEMORY_NAME =	ft_memalloc.c			\
				ft_memccpy.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memdel.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_bzero.c				\
				ft_swap.c				\
				ft_gnl.c				\
				ft_addncharbefore.c		\
				ft_memrev.c				\
				ft_flags.c				\
				ft_memjoinfreefirst.c	\

STR_FOLDER = str
STR_NAME	=	ft_strcat.c				\
				ft_strchr.c				\
				ft_strclr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strdel.c				\
				ft_strdup.c				\
				ft_strequ.c				\
				ft_striter.c			\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlen.c				\
				ft_strlen_c.c			\
				ft_strmap.c				\
				ft_strmapi.c			\
				ft_strncat.c			\
				ft_strncmp.c			\
				ft_strncpy.c			\
				ft_strnequ.c			\
				ft_strnew.c				\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strsplit.c			\
				ft_strstr.c				\
				ft_strsub.c				\
				ft_strtrim.c			\
				ft_wcslen.c				\
				ft_strlenwcs.c			\
				ft_char_index.c			\
				ft_strpbrk.c			\
				ft_strrstr.c			\
				ft_strrev.c				\
				ft_strcapitalize.c		\
				ft_strlowerize.c		\
				ft_strupperize.c		\
				ft_strncatindex.c		\
				ft_str_is_printable.c	\

LIST_FOLDER = list
LIST_NAME	=	ft_lstadd.c				\
				ft_lstdel.c				\
				ft_lstdelone.c			\
				ft_lstiter.c			\
				ft_lstmap.c				\
				ft_lstnew.c				\
				ft_lstpushback.c		\
				ft_lstrev.c				\
				ft_lstsize.c			\

PRINT_FOLDER = print
PRINT_NAME	=	ft_putchar.c			\
				ft_putchar_fd.c			\
				ft_putendl.c			\
				ft_putendl_fd.c			\
				ft_putnbr.c				\
				ft_putnbr_fd.c			\
				ft_putnbr_n.c			\
				ft_putstr.c				\
				ft_putstr_fd.c			\
				ft_printnchar.c         \
				ft_printmemory.c        \
				ft_putaddr.c			\
				ft_putdbl.c				\
				ft_printf.c				\
				ft_buffer.c				\

MATH_FOLDER = math
MATH_NAME	=	ft_bracket.c			\
				ft_sqrt.c				\
				ft_power.c				\
				ft_random.c				\
				ft_sort_int_tab.c		\
				ft_abs.c				\
				ft_biggest.c			\
				ft_smallest.c			\

PRINTF_FOLDER = printf_srcs
PRINTF_NAME	=	ft_m_count.c            \
				ft_last_char.c          \
				ft_take_infos.c         \
				ft_printf_s.c           \
				ft_printf_di.c          \
				ft_printf_o.c           \
				ft_printf_u.c           \
				ft_printf_p.c           \
				ft_printf_ms.c          \
				ft_printf_md.c          \
				ft_printf_x.c           \
				ft_printf_mx.c          \
				ft_printf_c.c           \
				ft_printf_mc.c          \
				ft_printf_n.c           \
				ft_printf_b.c           \
				ft_printf_momu.c        \
				ft_printf_bouxmx.c      \
				ft_printf_modulo.c      \

COLOR_FOLDER = color
COLOR_NAME	=	ft_blue.c				\
				ft_cyan.c				\
				ft_green.c				\
				ft_magenta.c			\
				ft_red.c				\
				ft_yellow.c				\

MALLOC_FOLDER = malloc
MALLOC_NAME	=	ft_malloc.c				\
				ft_free.c				\
				ft_realloc.c			\
				ft_show_alloc_mem.c		\
				ft_calloc.c				\
				ft_reallocf.c			\
				ft_malloc_good_size.c	\

TAB_FOLDER = tab
TAB_NAME = 		ft_free_tab.c			\
				ft_tabnew.c				\
				ft_tabdup.c				\
				ft_tablen.c				\

SUBFOLDERS =	$(CONV_FOLDER) $(CHAR_FOLDER) $(MEMORY_FOLDER)	\
				$(STR_FOLDER) $(LIST_FOLDER) $(PRINT_FOLDER)	\
				$(MATH_FOLDER) $(PRINTF_FOLDER) $(COLOR_FOLDER)	\
				$(MALLOC_FOLDER) $(TAB_FOLDER)					\

CONV_C = $(addprefix $(CONV_FOLDER)/, $(CONV_NAME))
CHAR_C = $(addprefix $(CHAR_FOLDER)/, $(CHAR_NAME))
MEMORY_C = $(addprefix $(MEMORY_FOLDER)/, $(MEMORY_NAME))
STR_C = $(addprefix $(STR_FOLDER)/, $(STR_NAME))
LIST_C = $(addprefix $(LIST_FOLDER)/, $(LIST_NAME))
PRINT_C = $(addprefix $(PRINT_FOLDER)/, $(PRINT_NAME))
MATH_C = $(addprefix $(MATH_FOLDER)/, $(MATH_NAME))
PRINTF_C = $(addprefix $(PRINTF_FOLDER)/, $(PRINTF_NAME))
COLOR_C = $(addprefix $(COLOR_FOLDER)/, $(COLOR_NAME))
MALLOC_C = $(addprefix $(MALLOC_FOLDER)/, $(MALLOC_NAME))
TAB_C = $(addprefix $(TAB_FOLDER)/, $(TAB_NAME))

SRC =	$(CONV_C) $(CHAR_C) $(MEMORY_C) $(STR_C)	\
		$(LIST_C) $(PRINT_C) $(MATH_C) $(PRINTF_C)	\
		$(COLOR_C) $(MALLOC_C) $(TAB_C)				\

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@ar rcs $@.a $(OBJ)
	@ranlib $@.a
	@echo "\033[32m[ ✔ ] $@ compiled\033[0m"

$(OBJ_FOLDER):
	@mkdir -p $@
	@mkdir -p $(addprefix $@/, $(SUBFOLDERS))
	@echo "creating $(NAME) object..."

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@$(CC) -I$(INCLUDE_FOLDER) -c $(FLAGS) $< -o $@

clean :
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "\033[33m[ ✔ ] $(NAME) objects deleted\033[0m"

fclean : clean
	@/bin/rm -f $(NAME).a
	@echo "\033[33m[ ✔ ] $(NAME) deleted\033[0m"

lib : all clean

re : fclean all

.PHONY: $(NAME) $(OBJ_FOLDER)