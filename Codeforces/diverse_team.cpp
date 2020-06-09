//http://codeforces.com/contest/988/problem/A

#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iostream>
    using namespace std;

int n,k;
vector<int> v, check;

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> k;
    int cnt=0;
    bool flag=0;
    check.resize(105,0);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(check[a]==0){
            check[a]=1;
            v.push_back(i);
            cnt++;
        }
        if(cnt>=k){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout << "NO";
    }else{
        cout << "YES" << endl;
        for(int i=0;i<k;i++){
            cout << v[i]+1 << " ";
        }
    }
    return 0;
}
