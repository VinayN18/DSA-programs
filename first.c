//CARD TRICK 1

#include <stdio.h>

int main()
{
  int a, col, p, q=0;
  int arr[7][3];
  int temp[21];
  int temp1[21];
  printf("Pick a card between 1 and 21 ");
  scanf("%d", &a);
  printf("Randomly picked card in Step 1 is %d \n",a);

  //Step 2 first time
  p=1;
  for(int i = 0; i<7; i++)
  {
    for(int j=0; j<3; j++)
    {
      printf("%d ", p);
      arr[i][j] = p;
      p++;
    }
  printf("\n");
  }

  p=0;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        temp[p] = arr[j][i];
        p++;
      }  
    }
 

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);


  switch (col)
  {
  case 1:  p = 14;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        if(p==20)
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p=0;
        }
        else
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p++;
        }
        
      }
      printf("\n");
    }
    break;

  case 2:  p = 0;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        printf("%d ",temp[p]);
        arr[i][j] = temp[p];
        p++;
      }
      printf("\n");
    }
    break;  
  
  case 3:  p = 7;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        if(p==20)
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p=0;
        }
        else
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p++;
        }
      }
      printf("\n");
    }
    break;

  default: printf("please enter a column number between 1 and 3 ");
    break;
  }


  p=0;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        temp[p] = arr[j][i];
        p++;
      }  
    }

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);

  
  switch (col)
  {
  case 1:  p = 14;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        if(p==20)
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p=0;
        }
        else
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p++;
        }
      }
      printf("\n");
    }
    break;

  case 2:  p = 0;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        printf("%d ",temp[p]);
        arr[i][j] = temp[p];
        p++;
      }
      printf("\n");
    }
    break;  
  
  case 3:  p = 7;
    for(int i=0; i<7; i++)
    {
      for(int j=0; j<3; j++)
      {
        if(p==20)
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p=0;
        }
        else
        {
          printf("%d ",temp[p]);
          arr[i][j] = temp[p];
          p++;
        }
      }
      printf("\n");
    }
    break;

  default: printf("please enter a column number between 1 and 3 ");
    break;
  }

  p=0;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        temp[p] = arr[j][i];
        p++;
      }  
    }

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);

  switch (col)
  {
  case 1: p=14;
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        if(p==20)
        {
          // temp[p] = arr[j][i];
          printf("%d ",temp[p]);
          // arr[i][j] = temp[p];
          temp1[q] = temp[p];
          p=0;
          q++;
        }
        else
        {
          // temp[p] = arr[j][i];
          printf("%d ",temp[p]);
          // arr[i][j] = temp[p];
          temp1[q] = temp[p];
          p++;
          q++;
        }
      }  
    }
    break;

  case 2: p=0;
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        // temp[p] = arr[j][i];
        printf("%d ",temp[p]);
        // arr[i][j] = temp[p];
        temp1[q] = temp[p];
        p++;
        q++;
      }
    }  
    break;  
  
  case 3: p=7;
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<7; j++)
      {
        if(p==20)
        {
          // temp[p] = arr[j][i];
          printf("%d ",temp[p]);
          temp1[q] = temp[p];
          p=0;
          q++;
        }
        else
        {
          // temp[p] = arr[j][i];
          printf("%d ",temp[p]);
          // arr[i][j] = temp[p];
          temp1[q] = temp[p];
          p++;
          q++;
        }
      }  
    }
    break;

  default: printf("please enter a column number between 1 and 3 ");
    break;
  }
  printf("\n");


printf("11th card from the top is %d and the 11th card from the bottom is %d which is the same card chosen by you", temp1[10], temp1[20-10]);

  return 0;
}