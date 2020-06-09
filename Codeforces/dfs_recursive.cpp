#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

vector<int> parents;
vector< vector<int> > graph;
vector<bool> visited;
int n, m;


bool dfs(int startP, int endP){
    visited[startP] = 1;
    if(startP == endP)
        return true;
    for(int i = 0; i < graph[startP].size(); i++){
        int a = graph[startP][i];
        if(!visited[a]){
            int flag = dfs(a, endP);
            if(flag){
                parents[a] = startP;
                return flag;
            }
        }
    }
    return 0;
}

void printPath(int startP, int endP){
	vector<int> ans;
	int cur_node = endP;
	while(cur_node != startP){
        ans.push_back(cur_node);
		cur_node = parents[cur_node];
	}
	ans.push_back(startP);
	vector<int> :: reverse_iterator it;
	for(it = ans.rbegin(); it != ans.rend(); it++){
		cout << *it << " ";
	}
}


int main(){
    freopen("input.txt","r", stdin);
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    parents.resize(n + 1, -1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int startP, endP;
    cin >> startP >> endP;
    if(dfs(startP, endP)){
        cout << "Yes" << endl;
        printPath(startP, endP);
    }else{
        cout << "No";
    }
    return 0;
}
