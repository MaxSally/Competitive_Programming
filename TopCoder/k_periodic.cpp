//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=396

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("k_periodic.txt","r",stdin);
    int n,k,res;
    cin >> n>>k;
    vector<int> a;
    a.resize(n);
    res=0;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
        vector<int>b,c;  //b:1;c:2
        b.resize(k);
        c.resize(k);
        for(int i=0;i<n;i++){
            if(a[i]==1){
                b[i % k]=b[i % k]+1;
            }else{
                c[i % k]=c[i % k]+1;
            }
        }
        for(int i=0;i<k;i++){
            if(b[i]<c[i]){
                res=res+b[i];
            }else{
                res=res+c[i];
            }
        }
    cout << res;
    return 0;
}
