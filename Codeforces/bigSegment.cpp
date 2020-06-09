//http://codeforces.com/problemset/problem/242/B

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("bigSegment.txt","r",stdin);
    vector<int> a,b;
    int n,output,minA,maxB;
    output =-1;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for( int i =0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    minA=a[0];
    maxB=b[0];
    for(int i =0; i<n; i++){
        if(minA>a[i]){
            minA=a[i];
        }
        if(maxB<b[i]){
            maxB=b[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]== minA && b[i] == maxB){
            output=i+1;
            break;
        }
    }
    cout << output;
    return 0;
}
