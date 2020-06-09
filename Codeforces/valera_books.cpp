#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;



int main(){
    freopen("valera_books.txt","r",stdin);
    int n,t,l,r,tong,res,boole;
    cin >> n >> t;
    vector<int> a;
    a.resize(n);
    boole=0;
    for(int i=0;i<n;i++){
        cin >> a[i];

    }
    for(int i=0;i<n;i++){
        if(a[i]<t){
            boole=1; //
        }
    }

    if(boole==0){
        cout << 0;
    }else
    {
        l=0;
        r=0;
        tong=0;
        while(a[l]>t){
            l=l+1;
        }
        r=l;
        tong=a[l];
        while((tong+a[r+1]) <= t && r+1<n){
            r=r+1;
            tong=tong+a[r];
        }
        res=r-l+1;
        while(r<n-1){
            r=r+1;
            tong=tong+a[r];
            if(tong<=t){
                res=r-l+1;
                //cout << res;
            }else{
                tong=tong-a[l];
                l=l+1;
                if(tong<=t){
                    res=r-l+1;
                }
            }
        }
        cout << res;
    }
    return 0;
}

