#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n; cin>>m;
  int arr[n+1][n+1];
  int visited[n+1]={0};
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++) cin>>arr[i][j]=0;
  }
  return 0;
}