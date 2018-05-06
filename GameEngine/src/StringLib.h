#ifndef _STRING_LIB
#define _STRING_LIB

/**
* Returns if a string starts with a specific sequence of characters
* @param a The string to search
* @param b The string to check for
* @return Returns 1 if b is in a and 0 otherwise
*/
int startsWithString(const char* a, const char* b);

/*
* Returns the index of the first occurance of a character in a string
* @param a The string to search in
* @param e The character to search for
* @return Returns the index of the first occurance of a character in a string
*/
int indexOfChar(const char* a, char e);

/*
* Returns a substring of the string a from indexes [start,end) (Note: calls malloc. Need to free return value)
* @param a The array to get the substring from
* @param start The start position of the substring (inclusive)
* @param end The end position of the substring (exclusive)
* @return Returns a substring of a
*/
char* sub(const char* a, int start, int end);

/*
* Returns the character at a specific index of the string a
* @param a The array to search
* @param index The index in the array to look
* @return Returns the character at specified index in the string
*/
char charAtIndex(const char* a, int index);

/*
* Returns 1 if the string a starts with string b else returns 0
* @param a The string to search
* @param b The string to search for
* @return Returns 1 if the string a starts with string b otherwise returns 0
*/
int endsWithString(const char* a, const char* b);

/*
* Returns the index of a specific character after a specific index in a string
* @param a The index to search
* @param e The character to search for
* @param offset The start index of the search
* @return Returns the index of the first occurance of the character e in the string a after the offset
*/
int indexOfCharAfterIndex(const char* a, char e, int offset);

/*
* Returns the length of a string
* @param a The string to get the length of
* @return Returns the length of the string
*/
int length(const char* a);

/*
* Returns a trimmed version of the string a (Note: calls malloc. Need to free return value)
* @param a The string to trim
* @return Returns a trimmed copy of a
*/
char* trim(char* a);

#endif