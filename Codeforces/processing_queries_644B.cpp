//https://codeforces.com/problemset/problem/644/B

#include<queue>
#include<iostream>
#include<stdio.h>
    using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("processing_queries_644B.txt","r",stdin);
    long long n,b;
    cin >> n >> b;
    queue<long long> a;
    for(int i=0;i<n;i++){
        long long t,d;
        cin >> t >>d;

        while(a.empty()==false && a.front()<=t){
            a.pop();
        }
        if(a.size()<=b){
            if(a.empty()==true){
                cout << t+d << " ";
                a.push(t+d);
            }else{
                cout << a.back()+d << " ";
                a.push(a.back()+d);
            }
        }else{
            cout << -1 << " ";
        }
    }

    return 0;
}
