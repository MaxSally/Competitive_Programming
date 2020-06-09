#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
    using namespace std;

bool compare(int a,int b){
    return a<b;
}

int main(){
    freopen("devu_439B.txt","r",stdin);
    int n,x;
    long long sum;
    cin >> n >> x;
    vector<long long> a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sum=0;
    sort(a.begin(),a.end(),compare);
    for(int i=0;i<n;i++){
        if((x-i)>1){
            sum=sum+a[i]*(x-i);
        }else{
            sum=sum+a[i];
        }
    }
    cout << sum;



    return 0;
}
