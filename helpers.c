#include "helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *Join(int argc, ...)
{
	va_list valist;
	va_start(valist, argc);

	int n_chars = 0;
	for (int i = 0; i < argc; i++) {
		n_chars += strlen(va_arg(valist, char *));
	}

	va_start(valist, argc);
	char *full_path = malloc(sizeof(char) * (n_chars + 1 + argc));
	*full_path = '\0';
	for (int i = 0; i < argc; i++) {
		char *str = va_arg(valist, char *);
		strncat(full_path, str, n_chars);

		if (i < argc - 1)
			strncat(full_path, OS_SEP, n_chars);
	}

	return full_path;
}
