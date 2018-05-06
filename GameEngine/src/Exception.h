#ifndef _EXCEPTION_H
#define _EXCEPTION_H
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

#define EXCEPTION_INDEXOUTOFBOUNDS 1
#define EXCEPTION_NULLPOINTER 2

/*
	Throws an index out of bounds exception and prints out the index it is trying to get along with some additional details about the error
	@param index The index that is out of bounds
	@param additionalDetails More details about the exception
	@param catchException If 1 it will return the ID of the exception else it will close the program
	@return Returns the ID of the exception in case the exception is to be caught if asked to
*/
int throwIndexOutOfBoundsException(int index, char* additionalDetails, char catchException);

/*
	Throws a null pointer exception.
	@param additionalDetails More details about the exception
	@param catchException If 1 it will return the ID of the exception else it will close the program
	@return Returns the ID of the exception in case the exception is to be caught if asked to
*/
int throwNullPointerException(char* additionalDetails, char catchException);

#endif