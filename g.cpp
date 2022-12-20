#include<iostream>
using namespace std ;

void quickSort(int input[], int size) {
    if(size == 0 || size == 1) return  ;
    int pos = 0 ;
    int p_e = input[0] ;
    for(int i=1 ; i<size ; i++){
        if(input[i] <= p_e){
            pos++ ;
        }
    }
    int t = input[pos] ;
    input[pos] = input[0] ;
    input[0] = t ; 
    int j=pos+1 ;
    for(int i=0 ; i<pos ; i++){
        if(input[i] > input[pos]){
            for( ; j<size ; j++){
                if(input[j] <= input[pos]){
                    int r = input[j] ;
                    input[j] = input[i] ;
                    input[i] = r ;
                    break ; 
                }
            }
        }
    }
    quickSort(input , pos) ;
    quickSort(input+pos+1 , size-pos-1) ;
}

int gandolas(int* arr , int n , int k){
    if(n<=0) return 0 ;
    if(arr[0]+arr[n-1]<=k) return 1+gandolas(arr+1 , n-2 , k) ;
    else return 1+gandolas(arr , n-1 , k) ;
    return 0 ;
}

int main(){
    int n , k ;
    cin >> n >> k;
    int arr[n] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    quickSort(arr,n) ;
    cout << gandolas(arr , n , k) ;
    return 0 ;
}