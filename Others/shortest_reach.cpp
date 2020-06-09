#include<vector>
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
    using namespace std;

//long maxN=10000;
vector< vector<int> > graph;

vector<int> visited,path;

queue<int> q;

void BFS(int s){
    int cnt=0;
    while(q.empty()==false){
        cnt++;
        s=q.front();
        q.pop();
        int z=graph[s].size();
        for(int i=0;i<z;i++){
            if(visited[graph[s][i]]==0){
                q.push(graph[s][i]);
                visited[graph[s][i]]=1;
                path[graph[s][i]]=6*cnt;

            }


        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("shortest_reach.txt","r",stdin);
    int z1;
    cin >> z1;
    for(int z2=0;z2<z1;z2++){
        int n,m;
        cin >> n>>m;
        graph.resize(n+1);
        visited.resize(n+1,0);
        path.resize(n+1,-1);
        for(int i=0;i<m;i++){
            int b,c;
            cin >> b >> c;
            graph[b].push_back(c);
            graph[c].push_back(b);
        }


        int s;
        cin >> s;
        q.push(s);
        visited[s]=1;
        BFS(s);

        for(int i=1;i<=n;i++){
            if(i!=s){
                cout << path[i]<< " ";
            }
        }
        cout << endl;
    }

    return 0;
}
