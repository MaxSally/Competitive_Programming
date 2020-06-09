//http://codeforces.com/problemset/problem/387/B

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    freopen("george and round.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector<int> a,b;
    a.resize(n);
    b.resize(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    int cnt=0;
    int j=0;
    int i=0;
    for(;i<n;i++){
            for(;j<m;j++)
            {
                if(b[j]>=a[i])
                {
                    cnt++;
                    j++;
                    break;
                }
            }
    }
    cout << n-cnt;
    return 0;
}
