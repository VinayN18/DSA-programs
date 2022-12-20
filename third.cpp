#include <iostream>
using namespace std;
string sel[21];
string d[7];
string s[7];
string f[7];
string g[7];
string reshuffle[21];
string lo[21];
const int j= rand()%21;
string li[21];
string symbols[] ={"Heart","Clubs","Spade", "Diamond"};
string numbers[] ={ "A","K","Q","J","2","3","4","5","6","7","8","9","10"};
string randomcards(){
    string rcard;
    int e = rand()% 4;
    int w = rand()% 13;
    rcard+=symbols[e];
    rcard+="of";
    rcard+=numbers[w];
    for(int g=0;g<21;g++){
        sel[g]={rcard};
    }
    
    for(int i=0;i<21;i++){
        li[i]=sel[i];
    }  
    return rcard;

    //string card = string rcard;
    //cout<< rcard<<endl;
}
void distribute(){ 
  cout<<"h ";
    for(int i=0;i<21;i++){
        if(i%3==1){
            
                d[i]=li[i];
            
        }if(i%3==0){
            
                s[i]=li[i];
            
        }else{
            
                f[p]=li[p];
            
        }
    }
    
    for(int i=0;i<7;i++){
        cout<< li[i] ;
    }
}

void pailing(){
    for(int a=0;a<1;a++){
        if(a==0){
            int r=0;
            for(int l=0;l<7;l++){
                if(d[l]==sel[j]){
                    for(int z=6;z<14;z++){
                        reshuffle[z]=d[z]; 
                    }
                }else{
                    r++;
                    if(r==7){
                        for( int z=0;z<7;z++){
                            reshuffle[z]=d[z];
                        }
                    }
                }
            }
            int w=0;
            for(int l=0;l<7;l++){
                if(s[l]==sel[j]){
                    for(int z=6;z<14;z++){
                        reshuffle[z]=s[6-z]; 
                    }
                }else{
                    w++;
                    if(w==7){
                        if(reshuffle[0]==d[0]){
                            for(int z=14;z<21;z++){
                                reshuffle[z]=s[14-z];
                            }
                        }else{
                            for( int z=0;z<7;z++){
                                reshuffle[z]=s[z];
                            }
                        }
                    }
                }
            }
            int x=0;
            for(int l=0;l<7;l++){
                if(f[l]==sel[l]){
                    for(int z=6;z<14;z++){
                        reshuffle[z]=f[6-z]; 
                    }
                }else{
                    x++;
                    if(x==7){
                        for(int z=14;z<21;z++){
                            reshuffle[z]=f[14-z];
                        }
                    }
                }
            } 
            for(int i=0;i<21;i++){
                li[i]=reshuffle[i];
            }
        }else{
            int k=0;
            for(int l=0;l<7;l++){
                if(d[l]==sel[j]){
                    for(int z=6;z<14;z++){
                        lo[z]=d[z]; 
                    }
                }else{
                    k++;
                    if(k==7){
                        for( int z=0;z<7;z++){
                            lo[z]=d[z];
                        }
                    }
                }
            int m=0;
            for(int l=0;l<7;l++){
                if(s[l]==sel[j]){
                    for(int z=6;z<14;z++){
                        lo[z]=s[6-z]; 
                    }
                }else{
                    m++;
                    if(m==7){
                        if(reshuffle[0]==d[0]){
                            for(int z=14;z<21;z++){
                                lo[z]=s[14-z];
                            }
                        }else{
                            for( int z=0;z<7;z++){
                                lo[z]=s[z];
                            }
                        }
                    }
                }
            }
            int o=0;
            for(int l=0;l<7;l++){
                if(f[l]==sel[l]){
                    for(int z=6;z<14;z++){
                        lo[z]=f[6-z]; 
                    }
                }else{
                    o++;
                    if(o==7){
                        for(int z=14;z<21;z++){
                            lo[z]=f[14-z];
                        }
                    }
                }
            } 
            for(int i=0;i<21;i++){
                li[i]=lo[i];
            }
        }
    }
}
}
int main(){
    for( int i=0;i<21;i++){
        randomcards();   
    }
    const string choosen =sel[j];
    for(int i=0;i<3;i++){
        if(i>1){
            distribute();
        }else{
            distribute();
            pailing();
        }
    }
    if(li[10]==sel[j]){
        cout<<'T';
    }
}