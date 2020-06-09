//http://acm.timus.ru/problem.aspx?space=1&num=1837

#include<stdio.h>
#include<iostream>
#include<vector>
#include <string>
#include <map>
#include <queue>
#define pb push_back
using namespace std;
const int MAX_N = 30000+3;
int n;
int cnt;
string a,b,c;
int x,y,z;
map<string,int> mp;
map<string,int>:: iterator it;
vector<int>graph[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int check(string &s){
    if(!mp[s])
        mp[s] = cnt++;
    return mp[s];
}

void BFS(int src){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;
    while(q.size()){
        x = q.front();
        q.pop();
        for(int i = 0 ; i < graph[x].size();i++){
            y = graph[x][i];
            if(!visited[y]){
                visited[y]=1;
                q.push(y);
                dist[y]=dist[x]+1;

            }
        }
    }
}

int main(){
    freopen("isen_num.txt","r",stdin);
    cin >> n;
    cnt = 1;
    for(int i = 0 ; i < n ;i++){
        cin >> a >> b >> c;
        x = check(a);
        y = check(b);
        z = check(c);
        graph[x].pb(y);
        graph[x].pb(z);
        graph[y].pb(x);
        graph[y].pb(z);
        graph[z].pb(x);
        graph[z].pb(y);
    }
    //memset(visited,0,MAX_N);
    for(int i = 0 ; i < MAX_N; i++){
        dist[i] = 1e9;
        visited[i] = false;
    }
    if(mp.find("Isenbaev")!=mp.end()){
        BFS(mp["Isenbaev"]);
    }

    for(it = mp.begin(); it!=mp.end();it++){
        cout << it->first<<" ";
        if(dist[it->second] >= 1e9){
            cout<<"undefined\n";
        }
        else
            cout <<dist[it->second]<<endl;
    }

}
