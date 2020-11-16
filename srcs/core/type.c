#include "ft_ssl.h"


int				digest(char *digest, t_ssl *ssl)
{
	if (!ft_strcmp(digest, "md5"))
		ssl->digest |= digest_md5;
	else if (!ft_strcmp(digest, "sha1"))
		ssl->digest |= digest_sha1;
	else if (!ft_strcmp(digest, "sha256"))
		ssl->digest |= digest_sha256;
	else if (!ft_strcmp(digest, "sha224"))
		ssl->digest |= digest_sha224;
	else if (!ft_strcmp(digest, "sha384"))
		ssl->digest |= digest_sha384;
	else if (!ft_strcmp(digest, "sha512"))
		ssl->digest |= digest_sha512;
	else if (!ft_strcmp(digest, "base64"))
		ssl->digest |= digest_base64;
	else
		return (help(digest, 0));
	return (1);
}

void		check_type(t_ssl *ssl)
{
	if (ssl->digest & digest_md5 || ssl->digest & digest_sha224
		|| ssl->digest & digest_sha256 || ssl->digest & digest_sha1
		|| ssl->digest & digest_sha384 || ssl->digest & digest_sha512)
	{
		ssl->type |= is_md5;
	}
	else if (ssl->digest & digest_base64)
		ssl->type |= is_des;
}
