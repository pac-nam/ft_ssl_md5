#include "ft_ssl_des.h"

void			set_fds(t_ssl_des *des)
{
	des->input_file_fd = 0;
	des->output_file_fd = 1;
}

