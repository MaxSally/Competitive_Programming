#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
    using namespace std;

int main(){
    freopen("tower_37A.txt","r",stdin);
    int n,maxInd,cnt;
    cin >> n;
    vector<int> a,b;
    a.resize(n);
    b.resize(1000+1,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    maxInd=1;
    cnt=0;
    for(int i=2;i<1001;i++){
        if(b[maxInd]<=b[i]){
            maxInd=i;
        }
    }
    for(int i=1;i<1001;i++){
        if(b[i]>0){
            cnt++;
        }
    }

    cout << b[maxInd] << " " << cnt;

    return 0;
}
