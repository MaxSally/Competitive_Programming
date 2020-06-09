#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("eugeny_arrays.txt","r",stdin);
    int n,m,duong;
    duong=0;
    cin >> n >> m;
    vector<int> a,m1,m2;
    m1.resize(m);
    m2.resize(m);
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==1){
           duong=duong+1;
        }
    }
    if(duong>(n-duong)){
        duong=n-duong;
    }
    for(int i=0;i<m;i++){
        cin >> m1[i] >> m2[i];
        if(((m2[i]-m1[i]+1) % 2)==1){
            cout << 0 << endl;
        }else{
            if((m2[i]-m1[i]+1)/2<=duong){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
