/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:54:05 by tbleuse           #+#    #+#             */
/*   Updated: 2018/05/19 12:33:50 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SSL_H
# define __FT_SSL_H
# define FT_SSL_MD5 "md5\nsha256\nsha1\nsha384\nsha512\nbase64"
# if __APPLE__
#  define WRAP 0
# elif __linux__
#  define WRAP 76
# endif
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft.h"
# include "md5.h"

typedef struct			s_opt
{
	char				**args_s;
}						t_opt;

typedef struct			s_ssl
{
	char				**files;
	char				*line;
	size_t				size_line;
	size_t				nb_arg_s;
	size_t				nb_args_s;
	t_opt				opt;
	short				args;
	short				digest;
	short				type;
}						t_ssl;

/*
** Flag ft_ssl_md5
** -p : echo STDIN to STDOUT and append the checksum to STDOUT
** -q : quiet mode
** -r : reverse the format of the output
** -s : print the sum of the given string
************************************************
** Flag ft_ssl_des
** -a : decode/encode the input/output in base64, depending on the encrypt mode
** -d : decrypt mode
** -e : encrypt mode (default)
** -i : input file for message
** -k : key in hex is the next arguement.
** (Behave like openssl des -K not openssl des -k)
** -o : output file for message
** -p : password in ascii is the next argument.
** (Behave like a modifiedd openssl des -pass not like openssl des -p or -P)
** (A verbose explanation is given in the next section)
** -s : the salt in hex is the next argument.
** (Behave like openssl des -S)
** -v : initialization vector in hex is the next argument.
** (Behave like openssl des -iv not openssl des -v)
*/

typedef enum			e_args
{
	FLAG_p = 1 << 0,
	FLAG_q = 1 << 1,
	FLAG_r = 1 << 2,
	FLAG_s = 1 << 3,
}						t_args;

/*
** md5 and sha256 = ft_ssl_md5
** sha1, sha384, sha512 = bonus - ft_ssl_md5
********************************************
** base64, des-ecb and des-cbc = ft_ssl_des
** des-ofb, des3, des3-ecb
** des3-cbc and des3-ofb = bonus - ft_ssl_des
*/

typedef enum			e_digest
{
	digest_md5 = 1 << 0,
	digest_sha256 = 1 << 1,
	digest_sha1 = 1 << 2,
	digest_sha224 = 1 << 3,
	digest_sha384 = 1 << 4,
	digest_sha512 = 1 << 5,
	digest_base64 = 1 << 6,
	digest_des = 1 << 7,
	digest_des_ecb = 1 << 8,
	digest_des_cbc = 1 << 9,
	digest_des_ofb = 1 << 10,
	digest_des3 = 1 << 11,
	digest_des3_ecb = 1 << 12,
	digest_des3_cbc = 1 << 13,
	digest_des3_ofb = 1 << 14,
}						t_digest;

/*
** is_md5 = ft_ssl_md5
** is_des = ft_ssl_des
** is_rsa = ft_ssl_rsa
*/

typedef enum			e_type
{
	is_md5 = 1 << 0,
	is_des = 1 << 1,
}						t_type;

uint32_t				revers_uint32(uint32_t n);
int						ft_ssl_md5(t_ssl *ssl, int ac, char **av);
int						core(int ac, char **av);
int						add_files(t_ssl *ssl, char **av, int ac, int start);
void					calcargs_s(char **av, t_ssl *ssl);
int						digest(char *digest, t_ssl *ssl);
int						parser(char **av, t_ssl *ssl);
void					check_type(t_ssl *ssl);
t_md5					*ft_md5(uint8_t *str, size_t size_line);
int						run(t_ssl *ssl);

void					compute_sha224(t_ssl *ssl);
void					print_sha224_fd0(t_ssl *ssl);
char					*sha224(const char *m);
char					*sha224_fd(const int fd);
char					*sha224_size(const char *m, size_t length);

void					compute_sha256(t_ssl *ssl);
void					print_sha256_fd0(t_ssl *ssl);
char					*sha256(const char *m);
char					*sha256_fd(const int fd);
char					*sha256_size(const char *m, size_t length);

void					compute_sha384(t_ssl *ssl);
void					print_sha384_fd0(t_ssl *ssl);
char					*sha384(const char *m);
char					*sha384_fd(const int fd);
char					*sha384_size(const char *m, size_t length);

void					compute_sha512(t_ssl *ssl);
void					print_sha512_fd0(t_ssl *ssl);
char					*sha512(const char *m);
char					*sha512_fd(const int fd);
char					*sha512_size(const char *m, size_t length);

int						help(char *arg, int ret);
void					print(t_ssl *ssl, t_md5 *md5);
void					free_and_exit(t_ssl *ssl);
int						read_file(int fd, t_ssl *ssl);
int						ft_ssl_des(t_ssl *ssl, char **av);
#endif
