//http://codeforces.com/contest/1005/problem/A

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <map>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> b;
    b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int pre = b[0];
    queue<int> q;
    for(int i = 1; i < n; i++){
        int a = b[i];
        if( a <= pre){
            q.push(pre);
        }
        pre = a;
    }
    q.push(b[n-1]);
    cout << q.size() << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
