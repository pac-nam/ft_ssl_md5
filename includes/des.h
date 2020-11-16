#ifndef __DES_STRUCT_H
# define __DES_STRUCT_H

# include "ft_ssl_des.h"
# include <stdint.h>

/*
**	add this prototypes in the header
**	char			*sha256(const char *m)
**	char			*sha256_fd(const int fd)
**	char			*sha256_size(const char *m, size_t length);
*/

typedef struct		s_des_tables {
	uint64_t		keys[16];
	uint8_t			initial_transposition[64];
	uint8_t			final_transposition[64];
	uint8_t			expansion[48];
	uint8_t			selection[8][4][16];
	uint8_t			round_transposition[32];
}					t_des_tables;

int			des_decrypt(int input_fd, int output_fd, uint64_t key);
int			des_encrypt(int input_fd, int output_fd, uint64_t key);
void		get_keys(uint64_t res[16], uint64_t prim);
void		init_tables(t_des_tables *tables, uint64_t primary_key);

#endif
