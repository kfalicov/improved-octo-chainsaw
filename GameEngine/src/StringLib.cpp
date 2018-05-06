#include "StringLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exception.h"

int startsWithString(const char* a, const char* b)
{
	if (a == NULL || b == NULL)
	{
		throwNullPointerException("At parameter in StartWithString()", 0);
	}
	if (strncmp(a, b, strlen(b)) == 0) return 1;
	return 0;
}

int indexOfChar(const char* a, char e)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in IndexOFChar()", 0);
	}
	return strchr(a, e) - a;
}


char* sub(const char* a, int start, int end)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in Substring()", 0);
	}
	if (start > end)
	{
		int tmp = start;
		start = end;
		end = tmp;
	}
	if (start < 0 || start > length(a))
	{
		throwIndexOutOfBoundsException(start, "Start out of range in SUB()", 0);
	}
	if (end < 0 || end > length(a))
	{
		throwIndexOutOfBoundsException(end, "End out of range in SUB()", 0);
	}

	char* result = (char*)malloc((end - start + 1) * sizeof(char));
	if (result == NULL)
	{
		throwNullPointerException("Malloc Returned Null in SUB()", 0);
	}
	int counter = 0;
	int i = start;
	for (; i < end; i++)
	{
		result[counter] = a[i];
		counter++;
	}
	result[counter] = 0;
	return result;
}

char charAtIndex(const char* a, int index)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in Char At Index()", 0);
	}
	if (index < 0 || index > length(a))
	{
		throwIndexOutOfBoundsException(index, "At parameter in Char At Index()", 0);
	}
	return a[index];
}


int endsWithString(const char* a, const char* b)
{
	if (a == NULL || b == NULL)
	{
		throwNullPointerException("At parameter in Ends With String()", 0);
	}
	int i = length(a) - 1;
	int lb = length(b) - 1;
	int counter = 0;
	for (; i >= 0; i--)
	{
		if (a[i] != b[lb - counter])
		{
			return 0;
		}
		counter++;
	}
	return 1;
}
int indexOfCharAfterIndex(const char* a, char e, int offset)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in IndexOfCharAfterIndex()", 0);
	}

	int len = length(a);
	if (offset < 0 || offset > len)
	{
		throwIndexOutOfBoundsException(offset, "At parameter in Offset out of range()", 0);
	}
	int i = offset;
	for (; i < len; i++)
	{
		if (a[i] == e)
		{
			return i;
		}
	}
	return -1;
}
int length(const char* a)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in Length()", 0);
	}

	return strlen(a) + 1;
}

char* trim(char* a)
{
	if (a == NULL)
	{
		throwNullPointerException("At parameter in Trim()", 0);
	}
	char* result = (char*)malloc(length(a) * sizeof(char));
	if (result == NULL)
	{
		throwNullPointerException("Malloc Returned Null in Trim()", 0);
	}

	int i = 0;
	int len = length(a) - 1;
	int foundEndOfBeginningSpace = 0;
	int counter = 0;
	for (; i < len; i++)
	{
		if ((a[i] == '\n' || a[i] == '\t' || a[i] == ' ') && foundEndOfBeginningSpace == 0)
		{
			continue;
		}
		else
		{
			result[counter++] = a[i];
			foundEndOfBeginningSpace = 1;
		}
	}
	result[i] = 0;

	int j = strlen(result) - 1;
	for (; j >= 0; j--)
	{
		if (result[j] == '\n' || result[j] == '\t' || result[j] == ' ')
		{
			result[j] = 0;
		}
		else
		{
			break;
		}
	}

	return result;
}




