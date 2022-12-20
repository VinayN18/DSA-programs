#include<iostream>
#include<vector>
using namespace std;
int short (vector<vectorr<int>> &vec,int n,int m,int ind,int arr[]){
    
    
}
int shortest_path(vector<vectorr<int>> &vec) {
    
}
void addedge(vector<vectorr<int>> vec2[],int u,int v,int c){
    vec2[u][v]=c;
    vec2[v][u]=c;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vectorr<int>> vec2(n,vector<int> (m, 0));
    int u,v,c;
    for (int i=0;i<m;i++){
        cin>>u>>v>>c;
        addedge(vec2,u,v,c);
    }
    
}