//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=945

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
//#define visited sdfghj

int n, m;
vector< vector<int> > graph;
vector<int> visited;

//Cách 1;

bool color(){
    queue<pair<int,int> > q;
    q.push(make_pair(0, 1));
    visited[0] = 2;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
      //  cout <<"head " <<  a << " " << b << endl;
        for(int i = 0; i < graph[a].size(); i++){
            int c = graph[a][i];
        //    cout << c << endl;
            if(!visited[c]){
                visited[c] = b;
                int temp;
                if(b == 1){
                    temp = 2;
                }else{
                    temp = 1;
                }
          //      cout << c << " " << temp << endl;
                q.push(make_pair(c, temp));
            }else if(visited[c] == visited[a]){
                return 0;
            }
        }
        /*for(int i = 0; i < n; i++){
            cout << visited[i] << " ";
        }
        cout << endl;*/
    }
    return 1;
}


// Cách 2


bool color_cach2(int a, int mau){
    int temp;
    if(mau == 1){
        temp = 2;
    }else{
        temp = 1;
    }
    for(int i = 0; i < graph[a].size(); i++){
        int b = graph[a][i];
        if(!visited[b]){
            visited[b] = mau;
            if(!color_cach2(b, temp)){
                return 0;
            }
        }else if(visited[b] == visited[a]){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("input.txt","r",stdin);
    while(true){
        cin >> n;
        if(n == 0){
            return 0;
        }
        //cout << n;
        cin >> m;
        visited.clear();
        graph.resize(n);
        visited.resize(n, 0);
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        visited[0] = 2;
        if(color_cach2(0, 1)){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
        for(int i = 0; i < n; i++){
            graph[i].clear();
        }
        graph.clear();
    }

}
