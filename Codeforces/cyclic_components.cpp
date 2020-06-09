//http://codeforces.com/contest/977/problem/E

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, m;
vector<vector<int> > graph;
vector<bool> visited;
vector<int> degree, subGraph;


void dfs(int a){
    visited[a] = true;
    subGraph.push_back(a);
    for(int i = 0; i < graph[a].size(); i++){
        int b = graph[a][i];
        if(!visited[b])
            dfs(b);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    degree.resize(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    int cnt = 0;
    //cout << "yes" << endl;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            subGraph.clear();
            dfs(i);
            bool flag = true;
            for(int j = 0; j < subGraph.size(); j++){
                int a = subGraph[j];
                if(degree[a] != 2){
                    flag = false;
                }
                /*flag &= degree[a] == 2;
                cout << flag << endl;*/
            }
            //cout << i << " " << flag << endl;
            if(flag){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
