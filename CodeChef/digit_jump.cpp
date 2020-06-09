//https://www.codechef.com/problems/DIGJUMP#

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
//#define visited sdfghj

string s;
int n;
vector<vector<int> > graph;
vector<bool> visited;
vector<bool> visitedG;

int BFS(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visited[0] = 1;
    int cycle = 1;
    while(!q.empty()){
        int a = q.front().first;
        int cnt = q.front().second;
        //cout << a << " " << cnt << endl;
        q.pop();
        if(a == n-1){
            return cnt;
        }
        if(!visited[a + 1]){
            visited[a + 1] = 1;
            q.push(make_pair(a + 1,cnt + 1));
        }
        if(a >= 1 && !visited[a - 1]){
            visited[a - 1] = 1;
            q.push(make_pair(a - 1,cnt + 1));
        }
        if(!visitedG[s[a] - '0']){
            visitedG[s[a] - '0'] = 1;
            for(int i = 0; i < graph[s[a] - '0'].size(); i++){
                int b = graph[s[a] - '0'][i];
                if(!visited[b]){
                    visited[b] = 1;
                    q.push(make_pair(b, cnt + 1));
                }
            }
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> s;
    n = s.length();
    graph.resize(10);
    visited.resize(100000, 0);
    visitedG.resize(10,0);
    for(int i = 0; i < n; i++){
        graph[s[i] - '0'].push_back(i);
    }
    cout << BFS();
    return 0;
}
