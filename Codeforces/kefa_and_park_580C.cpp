//http://codeforces.com/problemset/problem/580/C

#include <stack>
#include <vector>
#include <iostream>
#include <stdio.h>
    using namespace std;

vector <int> cat;
vector < vector<int> > tree;
vector <bool> visited;

int n,m;

int DFS(int a, int cntC){
    if(cat[a]){
        cntC++;
    }else{
        cntC = 0;
    }
    if(cntC <= m){
        if(a != 1 && tree[a].size() == 1){
            return 1;
        }
        int sum = 0;
        for(int i = 0; i < tree[a].size(); i++){
            int b = tree[a][i];
            if(!visited[b]){
                visited[b] = 1;
                sum += DFS(b, cntC);
            }
        }
        return sum;
    }
    return 0;
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    tree.resize(n+1);
    cat.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> cat[i];
    }
    for(int i=1;i<n;i++){
        int xi, yi;
        cin >> xi >> yi;
        tree[xi].push_back(yi);
        tree[yi].push_back(xi);
    }
    visited.resize(n+1,false);
    visited[1]=true;
    cout << DFS(1, 0);
    return 0;
}
