#include <stdio.h>

enum boolean {
  NO, // Starts with 0
  YES, // Progresses with +1 from previous
};

enum escapes {
  BELL = '\a',
  BACKSPACE = '\b',
  TAB = 't',
};

enum months {
  JAN = 1,
  FEB,
  MAR,
  APR,
};

int main()
{
  enum months var_months = JAN;
  const char msg[] = "warning: ";

  printf("var_months = %d\n", var_months+1);
  printf("Constant message : %s", msg);
  
  return (0);
}
