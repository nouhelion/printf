#include "main.h"
/**
 * printf_exclusive_string - print exclusuives string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_exclusive_string(va_list val)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putChar('\\');
			_putChar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putChar('0');
				len++;
			}
			len = len + print_hex_aux(cast);
		}
		else
		{
			_putChar(s[i]);
			len++;
		}
	}
	return (len);
}