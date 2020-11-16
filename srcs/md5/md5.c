#include "ft_ssl.h"
#include <stdlib.h>

const uint32_t g_md5r[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21};

const uint32_t g_md5k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

int			init_md5(uint8_t *str, t_md5 *md5, size_t size_line)
{
	size_t	str_len;

	md5->msg_hash = NULL;
	md5->file_hash = NULL;
	if (size_line > 0)
		md5->msg_hash = ft_strlen((char *)str) > 0 ? (char *)str: NULL;
	else
		md5->file_hash = ft_strlen((char *)str) > 0 ? (char *)str: NULL;
	md5->h0 = 0x67452301;
	md5->h1 = 0xefcdab89;
	md5->h2 = 0x98badcfe;
	md5->h3 = 0x10325476;
	str_len = size_line > 0 ? size_line : ft_strlen((const char *)str);
	md5->msg_len = str_len + 1;
	while (md5->msg_len % 64 != 56)
		md5->msg_len++;
	if (!(md5->msg = ft_strnew(md5->msg_len + 64)))
		return (0);
	ft_memcpy((char*)md5->msg, (const char *)str, str_len);
	*(uint32_t*)(md5->msg + str_len) = 0x80;
	*(uint32_t*)(md5->msg + md5->msg_len) = (uint32_t)(8 * str_len);
	return (1);
}

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

void		hash_md5(t_md5 *m, int i)
{
	if (i < 16)
	{
		m->f = (m->b & m->c) | ((~m->b) & m->d);
		m->g = i;
	}
	else if (i < 32)
	{
		m->f = (m->d & m->b) | ((~m->d) & m->c);
		m->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		m->f = m->b ^ m->c ^ m->d;
		m->g = (3 * i + 5) % 16;
	}
	else if (i < 64)
	{
		m->f = m->c ^ (m->b | (~m->d));
		m->g = (7 * i) % 16;
	}
	m->swap = m->d;
	m->d = m->c;
	m->c = m->b;
	m->b = m->b + leftrotate((m->a + m->f + g_md5k[i] + m->w[m->g]), g_md5r[i]);
	m->a = m->swap;
}

t_md5		*prepare_print(t_md5 *md5) {
	if (!(md5->hash = ft_memalloc(33)))
		return (NULL);
	ft_utoa_base_no_malloc(revers_uint32(md5->h0), md5->hash, 16);
	ft_utoa_base_no_malloc(revers_uint32(md5->h1), md5->hash + 8, 16);
	ft_utoa_base_no_malloc(revers_uint32(md5->h2), md5->hash + 16, 16);
	ft_utoa_base_no_malloc(revers_uint32(md5->h3), md5->hash + 24, 16);
	ft_strdel(&md5->msg);
	return (md5);
}

t_md5 		*ft_md5(uint8_t *str, size_t size_line)
{
	size_t	offset;
	int		i;
	t_md5	*md5;

	offset = 0;
	if (!(md5 = (t_md5 *)ft_memalloc(sizeof(t_md5))))
		return (NULL);
	if (!(init_md5(str, md5, size_line)))
		return (NULL);
	while (offset < md5->msg_len)
	{
		i = -1;
		md5->w = (uint32_t *)(md5->msg + offset);
		md5->a = md5->h0;
		md5->b = md5->h1;
		md5->c = md5->h2;
		md5->d = md5->h3;
		while (++i < 64)
			hash_md5(md5, i);
		md5->h0 += md5->a;
		md5->h1 += md5->b;
		md5->h2 += md5->c;
		md5->h3 += md5->d;
		offset += 64;
	}
	return (prepare_print(md5));
}
