#include "sha256.h"


uint32_t	rotrn(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

uint32_t	maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	sigma_maj(uint32_t x, uint32_t n)
{
	if (n == 0)
		return (rotrn(x, 2) ^ rotrn(x, 13) ^ rotrn(x, 22));
	return (rotrn(x, 6) ^ rotrn(x, 11) ^ rotrn(x, 25));
}

uint32_t	sigma_min(uint32_t x, uint32_t n)
{
	if (n == 0)
		return (rotrn(x, 7) ^ rotrn(x, 18) ^ (x >> 3));
	return (rotrn(x, 17) ^ rotrn(x, 19) ^ (x >> 10));
}
