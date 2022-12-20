#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void CountSort(int a[], int b[], int n, int max){
  for(int i=0;i<n;i++) b[a[i]]++;
  int i=0, j=0;
  while(i<max+1){
    if(b[i]>0){
      a[j]=i;
      j++;
      b[i]--;
    }
    else i++;
  }
}
int main(){
  int n,R,A,max=0,total=0,cnt=0,p=0; cin>>n; cin>>R; cin>>A;
  int grades[n],assignments[n],lessassign[n],sortlessassign[n],lessgrade[n];
  for(int i=0;i<n;i++){
    cin>>grades[i];
    total+=grades[i];
    cin>>assignments[i];
    if(grades[i]<R){
      lessgrade[p]=grades[i];
      lessassign[p]=assignments[i];
      sortlessassign[p]=assignments[i];
      if(max<lessassign[p]) max=lessassign[p];
      p++;
    }
  }
  int temp[max+1]={0};
  CountSort(sortlessassign,temp,p,max);
  if(total>=n*A){
    cout<<0;
    return 0;
  }
  for(int i=0;i<p;i++){
    for(int j=0;j<p;j++){
      if(sortlessassign[i]==lessassign[j]){
        if((lessgrade[j]<R)&&(total<n*A)){
          total+=1;
          cnt+=sortlessassign[i];
          lessgrade[j]++;
          j=-1;
        }
      }
    }
  }
  cout<<cnt;
  return 0;
}