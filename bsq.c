#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




#include <stdio.h>
int main() 
{
  //char *str[9] = {
  /*char str[9][27] = {
  "...........................",
  "....o......................",
  "............o..............",
  "...........................",
  "....o......................",
  "...............o...........",
  "...........................",
  "......o..............o.....",
  "..o.......o................"
  };*/

  /*char str[6][12] = {
  "............",
  ".......o....",
  "............",
  "....o...o...",
  "......o.....",
  "............"
  };*/

  char str[6][12] = {
  "...........",
  ".......o....",
  "............",
  "...o........",
  "............",
  "............"
  };
  
  int i = 0;
  int j = 0;
  /*while(i < 9)
    {
      printf("%s\n", str[i]);
      i++;
    }
  printf("\n");*/

  while(i < 6)
  {
    j = 0;
    while(j < 12)
    {
      printf("%c", str[i][j]);
      j++;
    }
    i++;
    printf("\n");
  }
  printf("\n");

  int		arr[6][12];
  i = 0;
  j = 0;
  while(i < 6)
  {
    j = 0;
    while(j < 12)
    {
      if (str[i][j] == '.')
        arr[i][j] = 0;
      if (str[i][j] == 'o')
        arr[i][j] = 1;
      printf("%d", arr[i][j]);
      j++;
    }
    i++;
    printf("\n");
  }
  printf("\n");

  
  i = 0;
  j = 0;
  while(i < 6)
  {
    j = 0;
    while(j < 12)
    {
      if(i == 0)
        arr[i][j] = arr[i][j]+arr[i][j-1];
      else if(j == 0)
        arr[i][j] = arr[i][j]+arr[i-1][j];
      else
        arr[i][j] = arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
      printf("%d", arr[i][j]);
      j++;
    }
    i++;
    printf("\n");
  }
  printf("\n");

  i = 0;
  j = 0;
  int n = 1;
  int s = 0;
  int size = 1;
  while(i < 6)
  {
    j = 0;
    while(j < 12&& (i + n <=7))
    {
      s = 0;
      n = size;
      while(s == 0 && (j + n <= 13))
        {
          printf("i=%d", i);
          printf("j=%d", j);
          printf("s=%d", s);
          printf("n=%d", n);
          printf("v=%d ", arr[i+n-1][j+n-1]);
          if(i == 0 || j == 0)
          {
            s = arr[i+n-1][j+n-1];
            printf("s1=%d", s);
          }
          else
          {
            s = arr[i+n-1][j+n-1] - arr[i][j-n] - arr[i-n][j] + arr[i-n][j-n];
            printf("s1=%d", s);
          }
          if (s>0)
          {
            size = n;
            printf("size=%d", size);
          }
          n++;
          printf("\n");
        }
      j++;
    }
    i++;
    printf("\n");
  }
  printf("\n");
  
  
    return(0);
}
