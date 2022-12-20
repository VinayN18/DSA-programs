#include <iostream>
using namespace std;

int main(){
    int m,n ;
    cin >> m >> n ;
    cout << 2*(m*n) - (m+n) ;
    return 0;
}


///////////////////////////////////////////////////////
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int plant(int a,int b,int n,int m,void * x){int score=0;
    int (*arr)[m] = (int (*)[m])x;
    if (arr[a][b]==-1){
        if (a+1<n && b<m &&arr[a+1][b]!=-1){score++;}
        if (a-1<n && b<m && a-1>=0 && arr[a-1][b]!=-1){score++;}
        if (a<n && b+1<m && arr[a][b+1]!=-1){score++;}
        if (a<n && b-1<m && b-1>=0 && arr[a][b-1]!=-1){score++;}
        arr[a][b]=score;
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                score+=plant(i,j,n,m,arr);
            }
        }
    }
    return score;
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];int a,max=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int l=0;l<n;l++){
               for (int k=0;k<m;k++){
                   arr[l][k]=-1;}
                               }
            a=plant(i,j,n,m,arr);
            if (a>max){max=a;}
        }
    }cout<<max;
  return 0;
}