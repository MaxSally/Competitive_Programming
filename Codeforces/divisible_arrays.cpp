#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("divisible_arrays.txt","r",stdin);
    int n,minV,res;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    res=-1;
    minV=v[0];
    for(int i=1;i<n;i++){
        if(minV>v[i]){
            minV=v[i];
        }
    }
    res=minV;
    for(int i=0;i<n;i++){
        if(v[i] % res !=0){
            res=-1;
            break;
        }
    }
    cout << res;
    return 0;
}
