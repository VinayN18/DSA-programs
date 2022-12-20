//CARD TRICK 2

#include <stdio.h>

int main()
{
  int n, quotient, col, p;
  int arr[9][3];
  int rem[3];
  int temp[27];
  int temp1[27];

  printf("Mentally choose one card numbered between 1 to 27 \n");
  printf("can you please choose a number between 1 to 27 ? ");
  scanf("%d",&n);

  for(int i=0; i<3; i++)
  {
    rem[i] = 0;
  }

  quotient = n-1;
  p=2;
  while(quotient>0)
  {
    rem[p] = quotient%3;
    quotient = quotient / 3;
    p--;
  } 


  p=1;
  for(int i=0; i<9; i++)
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
      for(int j=0; j<9; j++)
      {
        temp[p] = arr[j][i];
        p++;
      }  
    }

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);
  // printf("%d", rem[2]);
  switch (rem[2])
  {
    case 0: 
    if(col==1)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    } 
    else if (col==2)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }

    else if(col==3)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }
    break;
    
    case 1: 
    if(col==1)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
    else if(col==3)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    break;

    case 2:
    if(col==1)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==3)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
      break;

    default: printf("Sorry!");
      break;
      
  }

  p=0;
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<3; j++)
    {
      printf("%d ", temp1[p]);
      arr[i][j] = temp1[p];
      p++;
    }
    printf("\n");
  }

  p=0;
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<9; j++)
    {
      temp[p] = arr[j][i];
      p++;
    }
  }

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);

  switch (rem[1])
  {
    case 0: 
    if(col==1)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    } 
    else if (col==2)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }

    else if(col==3)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }
    break;
    
    case 1: 
    if(col==1)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
    else if(col==3)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    break;

    case 2:
    if(col==1)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==3)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
      break;

    default: printf("Sorry!");
      break;
  }

  p=0;
  for(int i=0; i<9; i++)
  {
    for(int j=0; j<3; j++)
    {
      printf("%d ", temp1[p]);
      arr[i][j] = temp1[p];
      p++;
    }
    printf("\n");
  }

  p=0;
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<9; j++)
    {
      temp[p] = arr[j][i];
      p++;
    }
  }

  printf("Can you tell me the column in which your card is ");
  scanf("%d", &col);

  switch (rem[0])
  {
    case 0:
    if(col==1)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    } 
    else if (col==2)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }

    else if(col==3)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0;
        }
        else
        {
          temp1[i] = temp[p];
          p++;
        }
      }
    }
    break;
    
    case 1: 
    if(col==1)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
    else if(col==3)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    break;

    case 2:
    if(col==1)
    {
      p=9;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==2)
    {
      p=18;
      for(int i=0; i<27; i++)
      {
        if(p==26)
        {
          temp1[i] = temp[p];
          p=0; 
        }
        else
        {
          temp1[i] = temp[p];
          p++; 
        }
      }
    }
    else if(col==3)
    {
      p=0;
      for(int i=0; i<27; i++)
      {
        temp1[i] = temp[p];
        p++;
      }
    }
      break;

    default: printf("Sorry!");
      break;
  }

  printf("You choosed %d ", temp1[n-1]);

  return 0;
}  