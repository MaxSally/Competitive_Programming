struct triad{
    int x,y,z;
    triad(){

    }
    triad(int x, int y , int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

vector<vector<pair<int,int> > > graph;
vector<bool> visited;
vector<int> cost;
vector<int> path;
vector<triad> graph1;

int ans=0;
int n,m;

void prim(int x,int y,int z){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(z,y));
    pq.push(make_pair(z,x));
    if(x!=y){
        visited[x]=1;
        visited[y]=1;
        for(int i=0;i<graph[y].size();i++){
            int v=graph[y][i].first;
            int w=graph[y][i].second;
            pq.push(make_pair(v,y));
        }
        for(int i=0;i<graph[x].size();i++){
            int v=graph[x][i].first;
            int w=graph[x][i].second;
            pq.push(make_pair(v,x));
        }
    }

    cost[y]=0;
    cost[x]=z;
    while(!pq.empty()){

        int a=pq.top().second;
        pq.pop();
        visited[a]=1;
        for(int i=0;i<graph[a].size();i++){
            int v=graph[a][i].first;
            int w=graph[a][i].second;
            if(visited[w]==0 && v<cost[w]){
                cost[w]=v;
                pq.push(make_pair(v,w));
                path[w]=a;
            }
        }

    }
}


int prim2(){ //second best MST
    vector<int> path2;
    path2.resize(n+1);
    for(int i=0;i<path.size();i++){
        path2[i]=path[i];
    }

    int ans1=1e9;
    for(int i=0;i<graph1.size();i++){
        int x=graph1[i].x;
        int y=graph1[i].y;
        int z=graph1[i].z;

        if(path2[x]!=y && path2[y]!=x){

            cost.clear();
            visited.clear();
            cost.resize(n+1,1e9);
            visited.resize(n+1,0);
            prim(y,x,z);
            /*cout << "=========================================" << endl;
            cout << x<< " "<< y << " "<< z<< endl;
            for(int j=1;j<path.size();j++){
                cout <<j <<" "<< path[j]<< endl;
            }*/


            ans1=min(ans1,sum(cost));

        }

    }
    return ans1;


}
