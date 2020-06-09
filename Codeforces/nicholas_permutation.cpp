//http://codeforces.com/problemset/problem/676/A

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("permutation.txt","r",stdin);
    int n,dis,maxA,minA,indexMin,indexMax;
    vector<int> a;
    cin >> n;
    a.resize(n+1);
    for (int i =1;i<=n;i++){
        cin >> a[i];
    }
    minA=a[1];
    indexMin=1;
    maxA=a[1];
    indexMax=1;
    for( int i =1; i<=n;i++){
        if(minA>a[i]){
            minA=a[i];
            indexMin=i;
        }
        if(maxA<a[i]){
            maxA=a[i];
            indexMax=i;
        }
    }
    if(indexMin<indexMax){
        if((n-indexMax)>(indexMin-1)){
            indexMax=n;
        }else{
            indexMin=1;
        }
        dis=indexMax-indexMin;
    }else{
        if((n-indexMin)>(indexMax-1)){
            indexMin=n;
        }else{
            indexMax=1;
        }
        dis=indexMin-indexMax;
    }
    cout << dis;
    return 0;
}
