##############################################################
######################### BINARIES ###########################
##############################################################
NAME = ft_ssl

##############################################################
########################### COLORS ###########################
##############################################################

RED						=	"\033[31;1m"
GREEN					=	"\033[32;1m"
RESET					=	"\033[0m"

##############################################################
######################### VARIABLE ###########################
##############################################################

OS                      =       $(shell uname)
DEBUG                   =       -g3 -fsanitize=address
CC                      =       $(shell which gcc) -Wall -Werror -Wextra $(DEBUG)

##############################################################
####################### LIBFT & PRINTF #######################
############################ LIB #############################
##############################################################

LIBFTDIR        		=		libft

##############################################################
########################## HEADERS ###########################
##############################################################

INCLUDES                =		includes
HEADERLIB				=		$(LIBFTDIR)/$(INCLUDES)
HEADER					=		ft_ssl.h				\
								base64.h				\
								ft_ssl_des.h			\
								md5.h					\
								sha256.h				\
								sha512.h				\
								des.h					\

HEADERS					=		$(addprefix $(INCLUDES)/, $(HEADER))

CPPFLAGS				=		-I$(HEADERLIB)			\
								-I$(INCLUDES)			\

##############################################################
######################### LIBRARIES ##########################
##############################################################

LDFLAGS					=		-L$(LIBFTDIR)			\
								-lft

##############################################################
#################### SRCS & OBJS FOLDER ######################
##############################################################

SRCSDIR                 = 		srcs
OBJSDIR                 = 		objects

##############################################################
######################### SRCS MD5 ###########################
##############################################################

SRCSDIRMD5				=		$(SRCSDIR)/md5
OBJSDIRMD5				=		$(OBJSDIR)/md5

SRCMD5					=		md5.c					\
								run.c					\
								print.c					\

SRCSMD5					=		$(addprefix $(SRCSDIRMD5)/, $(SRCMD5))
OBJMD5					=		$(SRCMD5:%.c=%.o)

OBJSMD5					=		$(addprefix $(OBJSDIRMD5)/, $(OBJMD5))


##############################################################
######################## SRCS sha256 #########################
##############################################################

SRCSDIRSHA256			=		$(SRCSDIR)/sha256
OBJSDIRSHA256			=		$(OBJSDIR)/sha256

SRCSHA256				=		compute_sha256.c		\
								sha256.c				\
								sha256_block.c			\
								sha256_h_to_string.c	\

SRCSSHA256				=		$(addprefix $(SRCSDIRSHA256)/, $(SRCSHA256))
OBJSHA256				=		$(SRCSHA256:%.c=%.o)

OBJSSHA256				=		$(addprefix $(OBJSDIRSHA256)/, $(OBJSHA256))

##############################################################
######################## SRCS sha1 #########################
##############################################################

SRCSDIRSHA1				=		$(SRCSDIR)/sha1
OBJSDIRSHA1				=		$(OBJSDIR)/sha1

SRCSHA1					=

SRCSSHA1				=		$(addprefix $(SRCSDIRSHA1)/, $(SRCSHA1))
OBJSHA1					=		$(SRCSHA1:%.c=%.o)

OBJSSHA1				=		$(addprefix $(OBJSDIRSHA1)/, $(OBJSHA1))

##############################################################
######################## SRCS sha224 #########################
##############################################################

SRCSDIRSHA224			=		$(SRCSDIR)/sha224
OBJSDIRSHA224			=		$(OBJSDIR)/sha224

SRCSHA224				=		compute_sha224.c		\
								sha224.c				\

SRCSSHA224				=		$(addprefix $(SRCSDIRSHA224)/, $(SRCSHA224))
OBJSHA224				=		$(SRCSHA224:%.c=%.o)

OBJSSHA224				=		$(addprefix $(OBJSDIRSHA224)/, $(OBJSHA224))

##############################################################
######################## SRCS sha384 #########################
##############################################################

SRCSDIRSHA384			=		$(SRCSDIR)/sha384
OBJSDIRSHA384			=		$(OBJSDIR)/sha384

SRCSHA384				=		compute_sha384.c		\
								sha384.c				\

SRCSSHA384				=		$(addprefix $(SRCSDIRSHA384)/, $(SRCSHA384))
OBJSHA384				=		$(SRCSHA384:%.c=%.o)

OBJSSHA384				=		$(addprefix $(OBJSDIRSHA384)/, $(OBJSHA384))

##############################################################
######################## SRCS sha512 #########################
##############################################################

SRCSDIRSHA512			=		$(SRCSDIR)/sha512
OBJSDIRSHA512			=		$(OBJSDIR)/sha512

SRCSHA512				=		compute_sha512.c		\
								sha512.c				\
								sha512_block.c			\
								sha512_h_to_string.c	\

SRCSSHA512				=		$(addprefix $(SRCSDIRSHA512)/, $(SRCSHA512))
OBJSHA512				=		$(SRCSHA512:%.c=%.o)

OBJSSHA512				=		$(addprefix $(OBJSDIRSHA512)/, $(OBJSHA512))

##############################################################
######################## SRCS bas64 ##########################
##############################################################

SRCSDIRBASE64			=		$(SRCSDIR)/base64
OBJSDIRBASE64			=		$(OBJSDIR)/base64

SRCBASE64				=		base64.c				\
								base64_encode.c			\
								base64_decode.c			\

SRCSBASE64				=		$(addprefix $(SRCSDIRBASE64)/, $(SRCBASE64))
OBJBASE64				=		$(SRCBASE64:%.c=%.o)

OBJSBASE64				=		$(addprefix $(OBJSDIRBASE64)/, $(OBJBASE64))

##############################################################
######################### SRCS core ##########################
##############################################################

SRCSDIRCORE				=		$(SRCSDIR)/core
OBJSDIRCORE				=		$(OBJSDIR)/core

SRCCORE					=		help.c					\
								ft_ssl_md5.c			\
								core.c					\
								parser.c				\
								type.c					\
								args.c					\
								main.c					\

SRCSCORE				=		$(addprefix $(SRCSDIRCORE)/, $(SRCCORE))
OBJCORE					=		$(SRCCORE:%.c=%.o)

OBJSCORE				=		$(addprefix $(OBJSDIRCORE)/, $(OBJCORE))

##############################################################
####################### SRCS core DES ########################
##############################################################

SRCSDIRCORE_DES			=		$(SRCSDIR)/ft_ssl_des_core
OBJSDIRCORE_DES			=		$(OBJSDIR)/ft_ssl_des_core

SRCCORE_DES				=		ft_ssl_des.c				\
								help_des.c					\
								fds.c						\

SRCSCORE_DES			=		$(addprefix $(SRCSDIRCORE_DES)/, $(SRCCORE_DES))
OBJCORE_DES				=		$(SRCCORE_DES:%.c=%.o)

OBJSCORE_DES			=		$(addprefix $(OBJSDIRCORE_DES)/, $(OBJCORE_DES))


##############################################################
####################### COMPILATION ##########################
##############################################################

OBJS					=		$(OBJSCORE)					\
								$(OBJSCORE_DES)				\
								$(OBJSSHA256)				\
								$(OBJSMD5)					\
								$(OBJSSHA224)				\
								$(OBJSSHA384)				\
								$(OBJSSHA512)				\
								$(OBJSSHA1)					\
								$(OBJSBASE64)				\

OBJS_DIRS				=		$(addprefix objects/, $(shell ls -l1 srcs | tr '\n' ' ' ))

all: libft $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)

	@echo Compiling $(NAME) [$(GREEN)√$(RESET)]
	@$(CC) $(OBJS) $(LDFLAGS) $(CPPFLAGS) -o $@

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADERS)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

$(OBJSDIR):
	@mkdir -p $(OBJS_DIRS)

libft:
	@make -C $(LIBFTDIR)

clean:
	@echo Cleaning $(NAME) [$(GREEN)√$(RESET)]
	@rm -rf $(OBJSDIR)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@echo Purge $(NAME) [$(GREEN)√$(RESET)]
	@rm -rf $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: libft

.SUFFIXES: .c .o
