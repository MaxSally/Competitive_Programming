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
    while(q.empty()==false){
        s=q.front();
        q.pop();
        int z=graph[s].size();
        for(int i=0;i<z;i++){
            if(visited[graph[s][i]]==0){
                q.push(graph[s][i]);
                visited[graph[s][i]]=1;
                path[graph[s][i]]=s;

            }


        }
    }

}

void print(int s,int f){
    stack<int> st;


    while(true){
        st.push(f);
        f=path[f];
        if(f==-1){
            cout << "no such path";
            return;
        }else if(s==f){
            cout << s << " ";
            while(st.empty()==false){
                cout << st.top() << " ";
                st.pop();
            }

            break;
        }
    }

}

int main(){
    freopen("BFS_examples.txt","r",stdin);

    int v,e;
    cin >> v >> e;
    graph.resize(v);
    visited.resize(v,0);
    path.resize(v,-1);
    for(int i=0;i<e;i++){
        int b,c;
        cin >> b >> c;
        graph[b].push_back(c);
        graph[c].push_back(b);
    }


    int s,f;
    cin >> s >> f;
    q.push(s);
    visited[s]=1;
    BFS(s);

    print(s,f);
    return 0;
}
