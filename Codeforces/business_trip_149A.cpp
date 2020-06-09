#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
    using namespace std;

bool compare(int a,int b){
    return a>b;
}

int main(){
    freopen("business_trip_149A.txt","r",stdin);
    int k,sum,r;
    cin >> k;
    vector<int> a;
    a.resize(13);
    for(int i=1;i<=12;i++){
        cin >>a[i];
    }
    r=0;
    sum=0;
    if(k==0){
        cout << 0;
    }else{
        sort(a.begin()+1,a.end(),compare);
        while(sum<k && r<=12){
            r++;
            sum=sum+a[r];
        }
        if(r<=12){
            cout << r;
        }else{
            cout << -1;
    }
    }


    return 0;
}
