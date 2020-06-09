#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
    using namespace std;

bool compare(int a,int b){
    return a>b;
}

int main(){
    freopen("chores_169A.txt","r",stdin);
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin()+1,v.end(),compare);
    cout << v[a]-v[a+1];

    return 0;
}
