/*

Some tips:
1. Preferably write the code in your local environment. It will help you debug the code faster.
2. Always practice writing clean code.

Note:
Use of C++ STL or any external library is strictly prohibited.
*/
#include <iostream>
#include <stdio.h>

using namespace std;
  int a, col=-1, p;
  int arr[7][3], temp[21], temp1[21];
  const int r = 7;
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
  for(int i = 0; i<7; i++){
    for(int j=0; j<3; j++){
      if(arr[i][j] == a){
        col = j;
        break;
      }}
    if(col==0 || col==1 || col==2){
      break;
    }}
  return col;
}
//for storing column wise in an array
void storing(int p, int arr[r][c], int temp1[]){
  for(int i=0; i<3; i++){
      for(int j=0; j<7; j++){
        temp1[p] = arr[j][i];
        p++;
      }}}
//for piling up in a order
void piling(int col, int p, int temp[], int temp1[]){
    switch (col){
    case 0:  p = 7;
    for(int i=0; i<21; i++){
        if(p==13){
          temp[i] = temp1[p];
          p=0;
        }else if(p==6){
          temp[i] = temp1[p];
          p=14;
        }else{
          temp[i] = temp1[p];
          p++;
        }}
    break;

    case 1:  p = 0;
    for(int i=0; i<21; i++){
      temp[i] = temp1[p];
      p++;
    }
    break;  
  
    case 2:  p = 0;
    for(int i=0; i<21; i++){
        if(p==6){
          temp[i] = temp1[p];
          p=14;
        }else if(p==20){
          temp[i] = temp1[p];
          p=7;
        }else{
          temp[i] = temp1[p];
          p++;
        }}
    break;
  }}
//for printing the piled up array
void printing(int temp[]){
  for(int i=0; i<21; i++){
    printf("%d ", temp[i]);
  }
  printf("\n");
}
int main(){
  //loop for storing the input values in an array
  for(int i=0; i<21; i++){
    scanf("%d",&temp[i]);
  }
  scanf("%d", &a); //for storing the choosen card
  
  for(int q=0; q<3; q++){
  arranging(0, arr, temp);
  col = searching(a, -1, arr);
  storing(0, arr, temp1);
  piling(col, 0, temp, temp1);
  printing(temp);
  }
  return 0;
}  