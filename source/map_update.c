#include "../includes/so_long.h"

int	check_arg(const char	*argv)
{
	size_t	len;
	char *	string;

	len = 0;
	if ((string = ft_strrchr(argv, '.')))
	{
		len = ft_strlen(string);
		if (ft_memcmp(string, ".ber", len) == 0)
			return(1);
	}
	return (0);
}

