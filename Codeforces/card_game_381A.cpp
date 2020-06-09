#include<vector>
#include<stdio.h>
#include<iostream>
    using namespace std;

int main(){
    freopen("card_game_381A.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int i,j,b1,c1;
    i=0;
    j=n-1;
    b1=0;
    c1=0;
    while(i<=j){
        if(a[i]>a[j]){
            b1=b1+a[i];
            i=i+1;
        }else{
            b1=b1+a[j];
            j=j-1;
        }
        if(i>j){
            break;
        }
        if(a[i]>a[j]){
            c1=c1+a[i];
            i=i+1;
        }else{
            c1=c1+a[j];
            j=j-1;
        }
    }
    cout << b1 << " " << c1;
    return 0;
}
