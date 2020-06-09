//http://lightoj.com/volume_showproblem.php?problem=1041


#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair< int,int> > >pq;
vector<vector<pair<int,int> > > graph;
vector<bool> visited;
vector<int> cost;
vector<string> name;
int m;

void prim(){
    pq.push(make_pair(0,0));
    cost[0]=0;
    while(pq.empty()==false){
        int a=pq.top().second;
        visited[a]=1;
        pq.pop();
        for(int i=0;i<graph[a].size();i++){
            int b=graph[a][i].first; //weight
            int c=graph[a][i].second; //end node
            if(visited[c]==0 && b<cost[c]){
                cost[c]=b;
                pq.push(make_pair(b,c));
            }

        }
    }
}

int check(string a){

    for(int i=0;i<name.size();i++){
        if(a==name[i]){
            return i;
        }
    }
    return -1;

}


int main(){
    freopen("road_construction.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> m;
        name.clear();
        graph.clear();
        cost.clear();
        visited.clear();
        graph.resize(200);

        visited.resize(200,0);


        for(int i=0;i<m;i++){
            string a,b;
            int c;
            cin >> a >> b >> c;

            int d,e;
            if(check(a)==-1){
                name.push_back(a);
            }
            d=check(a);

            if(check(b)==-1){
                name.push_back(b);
            }
            e=check(b);

            graph[d].push_back(make_pair(c,e));
            graph[e].push_back(make_pair(c,d));

        }
        cost.resize(name.size(),1e9);
        prim();
        long long ans=0;
        bool flag=0;
        for(int i=0;i<cost.size();i++){
            if(visited[i]==1){
                ans+=cost[i];
            }else{
                cout << "Case " << ii+1 << ": Impossible" << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << "Case "<< ii+1 << ": " << ans << endl;
        }

    }
    return 0;
}

