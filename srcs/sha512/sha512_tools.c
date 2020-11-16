#include "sha512.h"

t_word	rotrn(t_word x, t_word n)
{
	return ((x >> n) | (x << (32 - n)));
}

t_word	ch(t_word x, t_word y, t_word z)
{
	return ((x & y) ^ (~x & z));
}

t_word	maj(t_word x, t_word y, t_word z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

t_word	sigma_maj(t_word x, t_word n)
{
	if (n == 0)
		return (rotrn(x, 28) ^ rotrn(x, 34) ^ rotrn(x, 39));
	return (rotrn(x, 14) ^ rotrn(x, 18) ^ rotrn(x, 41));
}

t_word	sigma_min(t_word x, t_word n)
{
	if (n == 0)
		return (rotrn(x, 1) ^ rotrn(x, 8) ^ (x >> 7));
	return (rotrn(x, 19) ^ rotrn(x, 61) ^ (x >> 6));
}
