int findSet(int u){
    return (parent[u] == u? u: parent[u] = findSet(parent[u]));
}

void unionSet(int a, int b){
    int u = findSet(a);
    int v = findSet(b);
    if(u != v){
        parent[u] = v;
    }
}
