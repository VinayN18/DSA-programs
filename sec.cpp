/*Some tips:
1. Preferably write the code in your local environment. It will help you debug the code faster.
2. Always practice writing clean code.
Note:
Use of C++ STL or any external library is strictly prohibited.*/
#include <iostream>
#include <stdio.h>

using namespace std;
  int a, n, col=-1, p;
  int arr[9][3], temp[27], temp1[27], rem[3] = {0,0,0};
  const int r = 9;
  const int c = 3;
//for arranging in three columns
 void arranging(int p, int arr[r][c], int temp[]){
  for(int i = 0; i<r; i++){
    for(int j=0; j<c; j++){
      arr[i][j] = temp[p];
      p++;
    }}}
//for searching the column number in which the choosen card is present
int searching(int a, int col, int arr[r][c]){
  for(int i = 0; i<r; i++){
    for(int j=0; j<c; j++){
      if(arr[i][j] == a){
        col = j;
        break;
      }}
    if(col==0 || col==1 || col==2){
      break;
    }}
    return col;} 
//for storing column wise in an array
void storing(int p, int arr[r][c], int temp1[]){
  for(int i=0; i<3; i++){
      for(int j=0; j<9; j++){
        temp1[p] = arr[j][i];
        p++;
      }}}
//for piling      
void piling(int ak, int col, int p, int temp[], int temp1[]){
  switch (ak){
    case 0: if(col==0){
      p=0;
      for(int i=0; i<27; i++){
        temp[i] = temp1[p];
        p++;
      }} 
    else if (col==1){
      p=9;
      for(int i=0; i<27; i++){
        if(p==17){
          temp[i] = temp1[p];
          p=0;
        }else if(p==8){
          temp[i] = temp1[p];
          p=18;
        }else{
          temp[i] = temp1[p];
          p++;
        }}}
      else if(col==2){
      p=18;
      for(int i=0; i<27; i++){
        if(p==26){
          temp[i] = temp1[p];
          p=0;
        }else{
          temp[i] = temp1[p];
          p++;
        }}}
    break;
    
    case 1: if(col==0){
      p=9;
      for(int i=0; i<27; i++){
        if(p==17){
          temp[i] = temp1[p];
          p=0; 
        }else if(p==8){
          temp[i] = temp1[p];
          p=18;
        }else{
          temp[i] = temp1[p];
          p++;
        }}}
    else if(col==1){
      p=0;
      for(int i=0; i<27; i++){
        temp[i] = temp1[p];
        p++;
      }}
    else if(col==2){
      p=0;
      for(int i=0; i<27; i++){
        if(p==8){
          temp[i] = temp1[p];
          p=18; 
        }else if(p==26){
          temp[i] = temp1[p];
          p=9;
        }
        else{
          temp[i] = temp1[p];
          p++; 
        }}}
    break;

    case 2: if(col==0){
      p=9;
      for(int i=0; i<27; i++){
        if(p==26){
          temp[i] = temp1[p];
          p=0; 
        }else{
          temp[i] = temp1[p];
          p++; 
        }}}
    else if(col==1){
      p=0;
      for(int i=0; i<27; i++){
        if(p==8){
          temp[i] = temp1[p];
          p=18; 
        }
        else if(p==26){
          temp[i] = temp1[p];
          p=9; 
        }else{
          temp[i] = temp1[p];
          p++; 
        }}}
    else if(col==2){
      p=0;
      for(int i=0; i<27; i++){
        temp[i] = temp1[p];
        p++;
        }}
      break;
      }}     
//for printing the piled up array
void printing(int temp[]){
  for(int i=0; i<27; i++){
    printf("%d ", temp[i]);
  }
  printf("\n");
}
  int main(){
  //loop for storing the input values in an array
  for(int i=0; i<27; i++){
    scanf("%d",&temp[i]);
  }
  scanf("%d", &a);//for storing the choosen card
  scanf("%d", &n);//for storing the number
  
  n = n-1;
  p=2;
  while(n>0){
    rem[p] = n%3;
    n = n / 3;
    p--;
  } 
  for(int q=2; q>-1; q--){
  arranging(0, arr, temp);
  col = searching(a, -1, arr);
  storing(0, arr, temp1);
  piling(rem[q], col, p, temp, temp1);
  printing(temp);
  }
  return 0;
}  