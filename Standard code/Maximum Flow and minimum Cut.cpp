//Dinic

struct Edge{
    int v, rev, c, f;
};

class MaxFlow{
private:
    int n, t;
    vector<vector<Edge> > g;
    vi pos, level;

    bool dinic_bfs(int s){
        level.assign(n, -1);
        queue<int> q; q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            rep(i, 0, g[u].size() - 1){
                Edge e = g[u][i];
                if(level[e.v] != -1 || e.c - e.f == 0) continue;
                q.push(e.v);
                level[e.v] = level[u] + 1;
            }
        }
        return (level[t] != -1);
    }

    int dinic_dfs(int u, int f){
        if(u == t) return f;
        for(;pos[u] < g[u].size(); ++pos[u]){
            Edge &e = g[u][pos[u]];
            if(level[e.v] - level[u] == 1 && e.c - e.f > 0){
                int df = dinic_dfs(e.v, min(f, e.c - e.f));
                if(df > 0){
                    e.f += df;
                    g[e.v][e.rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }

public:

    MaxFlow(int n){
        this->n = n;
        g.assign(n, vector<Edge>());
    }

    void printGraph(){
        rep(i, 0, n - 1){
            //debug(i); debug(g[i].size());
            cout << i << " ";
            rep(j, 0, (int)g[i].size() - 1){
                cout << g[i][j].v << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int a, int b, int c){
        g[a].pb({b, g[b].size(), c, 0});
        g[b].pb({a, g[a].size() - 1, 0, 0});
    }

    int findMaxFlow(int s, int t){
        this->t = t;
        int maxFlow = 0;
        while(dinic_bfs(s)){
            int df;
            pos.assign(n, 0);
            while(df = dinic_dfs(s, inf)){
                maxFlow += df;
            }
        }
        return maxFlow;
    }
};




//****Ford and Karp****//
struct Edge{
    int v, rev, c, f; //v = end node, rev = the reverse edge, c = capacity, f = current flow
    Edge(int v, int rev, int c, int f){
        this->v = v; this->rev = rev; this->c = c; this->f = f;
    }
};

class MaxFlow{
private:
    int n;
    vector<vector<Edge> > graph;
    vi delta, pNode, pEdge;

    void printGraph(){
        rep(i, 0, n - 1){
            cout << i << " ";
            rep(j, 0 , graph[i].size() - 1){
                cout << graph[i][j].v << " ";
            }
            cout << endl;
        }
    }
    bool findPath(int s, int t){
        //printGraph();
        queue<int> q;
        q.push(s);
        delta.assign(n, inf);
        pNode.assign(n, -1);
        pEdge.assign(n, -3);
        vector<bool> visited; visited.resize(n, false);
        visited[s]= 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++){
                //cout << "hello" << endl;
                Edge e = graph[u][i];
                if(visited[e.v] || (e.c - e.f) == 0) continue;
                q.push(e.v);
                visited[e.v] = 1;
                delta[e.v] = min(delta[u], e.c - e.f);
                pNode[e.v] = u;
                pEdge[e.v] = i;
            }
        }
        return visited[t];
    }

    int increaseFlow(int u, int v){
        int df = delta[v];
        for(int cur = v; cur != u; cur = pNode[cur]){
            //cout << cur << endl;
            int edge = pEdge[cur], node = pNode[cur];
            graph[node][edge].f += df;
            graph[cur][graph[node][edge].rev].f -= df;
        }
        return df;
    }
public:

    MaxFlow(int n){
        this->n = n;
        graph.assign(n, vector<Edge>());
    }


    void addEdge(int u, int v, int c){
        graph[u].pb(Edge(v, graph[v].size(), c, 0));
        graph[v].pb(Edge(u, graph[u].size() - 1, 0, 0));
    }

    int findMaxFlow(int s, int t){
        int maximumFlow = 0;
        while(findPath(s, t)){
            maximumFlow += increaseFlow(s, t);
        }
        return maximumFlow;
    }
};
