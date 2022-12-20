#include<iostream>
#include <climits>
using namespace std;
int I=INT_MAX;
void MST(void *x, int distance[], int t, int n){
  int temp=t;
  int (*arr)[n+1] = (int (*)[n+1])x;
  int track[n+1]={0};
  while(0!=1){
    track[temp]=1;
    for(int i=1;i<n+1;i++){
      if(arr[temp][i]!=0){
        if(distance[i]>distance[temp]+arr[temp][i]) distance[i]=distance[temp]+arr[temp][i];
      }
    }
    int min=I,temp1=1;
    for(int i=1;i<n+1;i++){
      if(track[i]==0 && distance[i]<min){
        min=distance[i];
        temp1=i;
      }
    }
    if(min==I) break;
    temp=temp1;
  }
  for(int i=1;i<n+1;i++){
    if(distance[i]==I) distance[i]=-1;
  }
}
int main(){
  int n,m,x,y,w,k,q,output=0; cin>>n; cin>>m;
  int arr[n+1][n+1],distance[n+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++) arr[i][j]=0;
  }
  for(int i=0;i<m;i++){
    cin>>x; cin>>y; cin>>w;
    arr[x][y]=w;
    arr[y][x]=w;
  }
  cin>>k;
  int splghats[k];
  for(int i=0;i<k;i++) cin>>splghats[i];
  cin>>q;
  for(int i=0;i<q;i++){
    int t; cin>>t;
    for(int i=0;i<n+1;i++){
      if(i==0||i==t) distance[i]=0;
      else distance[i]=I;
    }
    MST(arr,distance,t,n);
    int minimum=I;
    for(int i=0;i<k;i++){
      if(distance[splghats[i]]<minimum) minimum=distance[splghats[i]];
    }
    output+=minimum;
  }
  cout<<output;
  return 0;
}