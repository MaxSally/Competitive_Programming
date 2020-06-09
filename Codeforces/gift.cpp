//http://codeforces.com/problemset/problem/609/B

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;


int main(){
    freopen("best_gift1.txt","r",stdin);
    long long n,m,result;
    result=0;
    cin >> n >> m;
    vector<long long> a,b;
    a.resize(n+1);
    b.resize(m+1);
    for( int i =1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        long sum;
        sum=0;
        for( int j =1;j<=n;j++){
            if(a[j]==i){
                sum=sum+1;
            }
        }
        b[i]=sum;
    }
    for(int i=1;i<=m;i++){
        result=result+b[i]*(n-b[i]);
    }
    cout << result/2;

    return 0;
}
