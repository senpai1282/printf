#include "main.h"
/**
 * bi_calc - unsigned integers to base to ni
 * @bnum: unsigned integer to binary
 * Return: bi value of int
 */
unsigned int bi_calc(unsigned int bnum)
{
unsigned int numcount = 0;

if (bnum <= 0)
{
putsmychar('0');
return (1);
}

else if (bnum == 1)
{
putsmychar('1');
return (1);
}
else
{
numcount += bi_calc(bnum / 2);
putsmychar('0' + (bnum % 2));
numcount++;
return (numcount);
}
}