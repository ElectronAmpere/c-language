#include <stdio.h>

int strlen_temp(char s[])
{
  int length = 0;
  
  while (s[length] != '\0')
    ++length;

  return (length);
}

int main()
{
  char string[] = "Hello, world!";
  printf("Length of %s = %d\n", string, strlen_temp(string));
  return (0);
}
