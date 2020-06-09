//

#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;

int n,m;
vector<int> parents;
vector<bool> visited;

int findSet(int u){
    while(u!=parents[u]){
        u=findSet(parents[u]);
    }
    return u;
}

void unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    parents[b1]=a1;
}


int main(){
    //freopen("input.txt","r",stdin);
    int ii=1;
    while (true){
        cin >> n >> m;
        if(n==0 && m==0){
            break;
        }
        parents.clear();
        visited.clear();
        parents.resize(n+1);
        visited.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parents[i]=i;
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            unionSet(a,b);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            int a=findSet(parents[i]);
            visited[a]=1;
        }
        for(int i=1;i<=n;i++){
            cnt+=visited[i];
        }
        cout << "Case " << ii << ": " << cnt << endl;
        ii++;
    }
    return 0;
}
