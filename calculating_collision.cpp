#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n]={0};;int a;int collision=0;
    for (int i=0;i<m;i++){
        cin>>a;
        if (arr[a%n]==0){
            arr[a%n]=a;
        }
        else{collision++;}
    }
    cout<<collision;
  return 0;
}