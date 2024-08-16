#include <stdio.h>

#define GET_DIFF_16BIT(a, b) ((unsigned short)(((unsigned short)a) - ((unsigned short)b)))
#define TIMEOUT              (5000)
#define TRUE                 (1)
#define FALSE                (0)

int main()
{
  unsigned char  timer_start  = 0;
  unsigned short time_counter = 0;
  unsigned short current_time = 0;


  unsigned char iterator = 0;
  
  while(1){

    ++time_counter; // Increment counter to simulate the hardware timer.
    
    if((GET_DIFF_16BIT(time_counter, current_time) >= TIMEOUT) && (TRUE == timer_start))
    {
	timer_start = FALSE;
    }

    ++iterator;

    switch(iterator){

      case 1:
         current_time = time_counter;
         timer_start = TRUE;
         break;

      default:
        break;
     }
  }

  return (0);
}
