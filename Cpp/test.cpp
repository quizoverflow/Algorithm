#include <stdio.h>
int arr[5][5];

int main()
{
   for (register int i = 0; i < 4; i++)
   {
      int total = 0;
      for (register int j = 0; j < 4; j++)
      {
         scanf("%d", arr[i] + j);
         total += arr[i][j];
      }
      arr[i][4] = total;
   }
   for (register int j = 0; j < 5; ++j)
   {
      int stotal = 0;
      for (register int i = 0; i < 5; ++i)
         stotal += arr[i][j];
      arr[4][j] = stotal;
   }
   for (register int i = 0; i < 5; ++i)
   {
      for (register int j = 0; j < 5; ++j)
         printf("%d ", *(arr[i] + j));
      printf("\n");
   }
   
   return 0;
}