#ifndef __BASE64_H
# define __BASE64_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include "libft.h"

typedef struct	s_base64
{
	uint8_t		*msg;
	size_t		msg_size;
	char		*hash;
	size_t		hash_size;
	char		*hex;
	size_t		index;
	size_t		pad_count;
	uint32_t	h;
	uint8_t		h0;
	uint8_t		h1;
	uint8_t		h2;
	uint8_t		h3;
}				t_base64;

typedef struct	s_base64_decode
{
	uint8_t		*msg;
	size_t		msg_size;
	char		*str_decode;
	size_t		str_decode_size;
	char		*hex;
	uint8_t		*end;
	uint8_t		c;
	uint32_t	buff;
	size_t		index;
	size_t		iter;
}				t_base64_decode;

typedef struct	s_line
{
	char 		*line;
	size_t		size_line;
}				t_line;

char			*base64_encode(char *str, size_t size, char *hex);
char			*base64_decode(char *str, char *hex);
#endif
