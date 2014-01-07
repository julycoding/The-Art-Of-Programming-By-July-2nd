#include <stdio.h>
#include <assert.h>
#include <string.h>

char *mystrcpy(char* dest, const char *src)
{
	assert(dest != NULL && src != NULL);
	assert(dest < src || strlen(src) < (unsigned int)(dest - src));
	if (src == dest)
		return dest;
	char *ret = dest;
	while('\0' != (*dest++ = *src++))
		;
	return ret;
}

int main()
{
	char dest[1024];
	char src[] = "abcdef";
	mystrcpy(dest, src);
	printf("%s\n", dest);
	return 0;
}
