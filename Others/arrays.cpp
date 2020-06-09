#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("arrays.txt","r",stdin);
    vector<int> a,b;
    int k,m,na,nb;
    cin >> na >> nb >> k >> m;
    a.resize(na);
    b.resize(nb);
    for(int i=0;i<na;i++){
        cin >> a[i];
    }
    for(int i=0;i<nb;i++){
        cin >> b[i];
    }
    if(a[k-1]<b[nb-m]){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
