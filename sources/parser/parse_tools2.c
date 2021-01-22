#include "../../includes/parsing.h"

int		allowed_symbol(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '.' || c == ',' ||
	(c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}
