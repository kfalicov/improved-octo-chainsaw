#include "Exception.h"


int throwIndexOutOfBoundsException(int index, char* additionalDetails, char catchException)
{
	if (additionalDetails == NULL)
	{
		throwNullPointerException("IndexOutOfBoundsException was being thrown but ran into a NULLPointerException", 0);
	}
	fprintf(stderr, "ERROR: IndexOutOfBoundsException thrown: Index: %d, Details: %s\n", index, additionalDetails);
	if (catchException == 1)
	{
		return EXCEPTION_INDEXOUTOFBOUNDS;
	}
	exit(-1);
	return 0; // if this line runs this program has come back to life
}

int throwNullPointerException(char* additionalDetails, char catchException)
{
	if (additionalDetails == NULL)
	{
		throwNullPointerException("NULLPointerException was being thrown but ran into a NULLPointerException", 0);
	}
	fprintf(stderr, "ERROR: NULLPointerException thrown: Details: %s\n", additionalDetails);
	if (catchException == 1)
	{
		return EXCEPTION_NULLPOINTER;
	}
	exit(-1);
	return 0; // if this line runs this program has come back to life
}
