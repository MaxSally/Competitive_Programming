//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

int n,m,k,a,b,c;
vector<int> nV, mV;


int process(){
    a=0;
    b=0;
    c=0;
    while(k>0 && a<n && b<m){
        if(nV[a]<mV[b]){
            c=0;
            a++;
        }else{
            c=1;
            b++;
        }
        k--;
        //cout << a <<" "<< b << " " << c << endl;
    }
    if(a<n && k!=0){
        return nV[a-1+k];
    }

    if(b<m && k!=0){
        return mV[b-1+k];
    }

    if(c==0){
        return nV[a-1];
    }else{
        return mV[b-1];
    }

}

int main(){

    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        cin >> n >> m >> k;
        nV.clear();
        mV.clear();
        nV.resize(n);
        mV.resize(m);
        for(int j=0;j<n;j++){
            cin >> nV[j];
        }
        for(int j=0;j<m;j++){
            cin >> mV[j];
        }

        cout <<process() << endl;

    }


    return 0;
}


