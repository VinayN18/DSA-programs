#include<iostream>
using namespace std;
typedef struct point{
    int x,y;
}point;

int knight(int N, int M, int x1, int y1, int x2, int y2) {
    point q[100000];
    int **v;
    int cur=0,max=0,move=0,curstep=1; 
    v = (int **)calloc(1, sizeof(int*)*M);
    for(int i=0;i<M;i++) v[i]=(int*)calloc(1, sizeof(int)*N);
    x1--;y1--;x2--;y2--;
    q[max].x = x1;
    q[max].y = y1;
    v[y1][x1] = 1;
    max++;
    while(cur<max){
        while(curstep==v[q[cur].y][q[cur].x]){
        point *p = &q[cur];
        int curx, cury;
        if(p->x==x2 && p->y==y2) return v[p->y][p->x]-1;
        curx = p->x - 2;
        cury = p->y - 1;
        if(curx>=0 && cury>=0 && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x - 1; 
        cury = p->y - 2;
        if(curx>=0 && cury>=0 && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x + 1; 
        cury = p->y - 2;
        if (curx<N && cury>=0 && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x + 2; 
        cury = p->y - 1;
        if(curx<N && cury>=0 && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x + 2; 
        cury = p->y + 1;
        if(curx<N && cury<M && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x + 1; 
        cury = p->y + 2;
        if(curx<N && cury<M && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x - 1; 
        cury = p->y + 2;
        if (curx>=0 && cury<M && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        curx = p->x - 2; 
        cury = p->y + 1;
        if (curx>=0 && cury<M && !v[cury][curx]){
            q[max].x = curx;
            q[max].y = cury;
            v[cury][curx] = v[p->y][p->x]+1;
            max++;
            if(max>=100000) return -1;
        }
        move++;
        cur++;
      }
    curstep++;
  }
  return -1;
}

int main(){
  int A,B,C,D,E,F; cin>>A; cin>>B; cin>>C; cin>>D; cin>>E; cin>>F;
  cout<<knight(A,B,C,D,E,F);
  return 0;
}