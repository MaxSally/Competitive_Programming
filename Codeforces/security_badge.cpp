//http://codeforces.com/gym/101615/attachments/download/6308/20172018-acmicpc-pacific-northwest-regional-contest-div-1-en.pdf

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double



struct triple{
    int x, y, z;
};

int n, m, k, s, t;
vector<vector<triple> >graph;
vector <int> l, v;
vector <bool> visited;

bool compare(int a, int b){
    return a < b;
}

bool DFS(int a, int key){
    if(a == t){
        return 1;
    }

    for(int i = 0; i < graph[a].size(); i++){
        int b = graph[a][i].x;
        if(!visited[b] && graph[a][i].y <= key && graph[a][i].z >= key){
            visited[b] = 1;
            if(DFS(b, key)){
                return 1;
            }
        }
    }
    return 0;

}

int security(){
    int sum = 0;
    for(int i = 1; i < v.size(); i++){
        int a = v[i];
        visited.clear();
        visited.resize(n+1, 0);
        if(DFS(s, a)){
            sum += v[i] - v[i-1];
        }
    }
    return sum;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m >> k >> s >> t;
    graph.resize(n + 1);
    l.push_back(0);

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        triple temp;
        temp.x = b;
        temp.y = c;
        temp.z = d;
        graph[a].push_back(temp);
        l.push_back(c-1);
        l.push_back(d);
    }
    sort(l.begin(),l.end(),compare);
    v.push_back(0);
    for(int i = 1; i < l.size(); i++){
        if(l[i] != l[i-1]){
            v.push_back(l[i]);
        }
    }
    cout << security();
    return 0;
}
