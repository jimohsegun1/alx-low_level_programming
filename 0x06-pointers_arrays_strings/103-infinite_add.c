/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
  int len1 = 0, len2 = 0, carry = 0, sum = 0;
  int i, j;

  /* Calculate the lengths of n1 and n2 */
  while (n1[len1] != '\0')
    len1++;
  while (n2[len2] != '\0')
    len2++;

  /* Check if the result can be stored in r */
  if (len1 >= size_r || len2 >= size_r)
    return 0;

  /* Add the digits from right to left, and store the result in r */
  for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--)
    {
      sum = carry;
      if (i >= 0)
	sum += n1[i] - '0';
      if (j >= 0)
	sum += n2[j] - '0';

      if (sum >= 10)
	{
	  carry = 1;
	  sum -= 10;
	}
      else
	carry = 0;

      r[size_r - 1] = sum + '0';
      size_r--;
    }

  /* If the result is shorter than r, move the digits to the left */
  if (size_r > 0 && r[size_r - 1] != '\0')
    {
      for (i = 0; i < size_r; i++)
	r[i] = r[i + 1];
      r[i] = '\0';
    }

  /* Return a pointer to the result */
  return r;
}
