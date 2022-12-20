#include<iostream>
using namespace std;
int arr[500][500];
bool reachcoordinate(int x, int y, int n, int m){
  bool temp=false;
  if (x==0 || y==0 || x==n-1 || y==m-1) return true;
    for (int i=-1;i<=1 && !temp;i++){
        for (int j=-1 ;j<=1 && !temp;j++){
            if ((x+i>=0 && x+i<n) && (y+j>=0 && y+j<m)){
            if (x+i==0|| x+i==n-1 || y+j==0 || y+j==m-1 || arr[x+i][y+j]==1) temp=reachcoordinate(x+i,y+j,n,m);
           }
        }
    }
    return temp;
}
int main(){
  int n,m,x,y; cin>>n; cin>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin>>arr[i][j];
  }
  cin>>x; cin>>y;
  arr[x][y]==0 || !reachcoordinate(x,y,n,m) ? cout<<0 : cout<<1;
  return 0;
}