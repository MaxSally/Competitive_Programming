//

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

vector<vector<int> > graph;
vector<int> cost,energy;

int n,m;
const int infN=1e9;

void bellmanF(){
    for(int i=0;i<n-1;i++){

        for(int j=1;j<graph.size();j++){
            for(int h=0;h<graph[j].size();h++){
                if(cost[j] != infN && cost[j]+energy[graph[j][h]] <100 && cost[j]+energy[graph[j][h]]<cost[graph[j][h]]){
                    cost[graph[j][h]]=cost[j]+energy[graph[j][h]];
                }
            }

        }
    }
}

bool cycle(vector<int> cost){
     queue< int > q;

    bool flag=0;
        for(int j=1;j<graph.size();j++){
            for(int h=0;h<graph[j].size();h++){
                if(cost[j] != infN && cost[j]+energy[graph[j][h]] <100 && cost[j]+energy[graph[j][h]]<cost[graph[j][h]]){
                    cost[graph[j][h]]=cost[j]+energy[graph[j][h]];
                    q.push(graph[j][h]);
                    flag=1;
                }

            }
        }



    if(flag==0){
        return false;

    }else{
        vector<bool> visited;
        visited.resize(n+1,0);
        while(!q.empty()){

            int v=q.front();
            q.pop();
            visited[v]=1;

            if(v==n){
                return true;
            }
            for(int i=0;i<graph[v].size();i++){
                if(!visited[graph[v][i]]){
                  q.push(graph[v][i]);
                }
            }
        }

    }
    return false;

}

int main(){

    while(true){
        cin >> n;

        if(n==-1){
            break;
        }
        energy.resize(n+1);
        cost.resize(n+1,infN);
        graph.resize(n+1);

        for(int i=1;i<=n;i++){
            cin >> energy[i] >> m;
            energy[i]=-energy[i];

            for(int j=0;j<m;j++){
                int temp;
                cin >> temp;

                graph[i].push_back(temp);
            }
        }

        cost[1]=0;

        bellmanF();

        if(cost[n]<100){
            cout << "winnable" << endl;
        }else{
            if(cycle(cost)){
                cout << "winnable" << endl;
            }else{
                cout << "hopeless" << endl;
            }
        }
        for(int i=1;i<graph.size();i++){
            graph[i].clear();
        }
        graph.clear();
        cost.clear();
        energy.clear();


    }


    return 0;
}
