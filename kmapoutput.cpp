#include <stdio.h>
int main()
{
unsigned int w, x, y, z;
unsigned int f;


// printf("         yz      \n");
// printf("     00 01 11 10 \n");
// printf("   ______\n");


for (w = 0; 2 > w; w = w + 1)
{
    for (x = 0; 2 > x; x++){
         printf("w=%u%x || ", w,x);
    }



    for (y = 0; 2 > y; y = y + 1)
    {
       
        for (z = 0; 2 > z; z = z + 1)
        {
    
            y = x^z;

            f = (w|~x) & (~w|~y) & (w|x|~y) & 1;
            printf("%u  ", f);
        }
    }

    printf("\n");
}

return 0;
}