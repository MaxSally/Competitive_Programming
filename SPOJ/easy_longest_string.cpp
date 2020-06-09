//http://www.spoj.com/problems/ELIS/
#include<iostream>
#include<stdio.h>
#include<vector>
    using namespace std;

int n;
vector<int> a,b;

int maxV(){
    int maxN=0;
    for(int i=0;i<n;i++){
        if(maxN<b[i]){
            maxN=b[i];
        }
    }
    return maxN;
}

int findb(int i){
    int maxN=0;
    for(int j=0;j<i;j++){
        if(a[j]<a[i] && maxN<b[j]){
            maxN=b[j];
        }
    }
    return maxN;
}



int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    a.resize(n);
    b.resize(n,0);
    b[0]=1;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        b[i]=1+findb(i);
    }
    cout << maxV();

    return 0;
}
