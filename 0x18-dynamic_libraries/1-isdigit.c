/**
 * _isdigit - Determines whether the provided character is a digit or not.
 * @c: The character to be evaluated.
 * Return: Returns 1 if the character is a digit, and 0 otherwise.
 */
int _isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
