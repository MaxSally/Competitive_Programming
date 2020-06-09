#define _CRT_SECURE_NO_WARNINGS

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=989&mosmsg=Submission+received+with+ID+21707216
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;

vector<bool> visited;
vector<int> parents;
vector<vector<pair<int,int> > > graph;
int a, b, c;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


int findSet(int u) {
	while (u != parents[u]) {
		u = findSet(parents[u]);
	}
	return u;
}

void unionSet(int a, int b) {
	int a1 = findSet(a);
	int b1 = findSet(b);
	parents[b1] = a1;
}


void kruskal() {
	while (!pq.empty()) {
		int a = pq.top().first;
		int y = findSet(pq.top().second % 500);
		int x = findSet(int(pq.top().second / 500));
		//cout <<int(pq.top().second/500)<<" " << pq.top().second %500 << endl;
		pq.pop();
		if (x != y) {
            graph[y].push_back(make_pair(x,a));
            graph[x].push_back(make_pair(y,a));
			parents[y] = x;
		}
	}
}


/*int dijkstra(int a,int b){
int a1=findSet(a);
int b1=findSet(b);
if(a1!=b1){
return -1;
}
cost.clear();
path.clear();
path.resize(m+1,-1);
cost.resize(m+1,1e9);
for(int i=1;i<=m;i++){
for(int j=0;j<graph[i].size();j++){
cost[i]=min(cost[i],graph[i][j].first);
}

}
return cost[b];


}*/

int DFS(int x, int y) {
	if (x == y) {
		return 0;
	}
	int ans = 1e9;
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
        int w=graph[x][i].second;
        int v=graph[x][i].first;
		if (visited[v] == 0 && w != 1e9) {
			ans = min(max(w,DFS(v, y)), ans);
		}
	}
	visited[x] = 0;
	return ans;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
	int ii = 1;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (ii != 1) {
			cout << endl;
		}
		graph.clear();
        visited.resize(a+1,0);
		graph.resize(a + 1);
		parents.resize(a+1);
		for(int i=1;i<=a;i++){
            parents[i]=i;
		}
		visited.resize(a+1);

		for (int i = 0; i<b; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			//cout << x <<" "<< y << " " << z << endl;
			pq.push(make_pair(z, 500 * x + y));
		}
		cout << "Case #" << ii << endl;
		//floyd();
		kruskal();
		/*for(int i=1;i<=a;i++){
		cout << i<< " "<<parents[i] << endl;
		}*/
		//cout <<" YES" << endl;
		for (int i = 0; i<c; i++) {
			int x, y;
			cin >> x >> y;
            if(findSet(x)!=findSet(y)){
                cout << "no path" << endl;
            }else{
                int temp = DFS(x, y);
                if (temp != 1e9) {
                    cout << temp << endl;
                }
                else {
                    cout << "no path" << endl;
                }
            }

		}
		ii++;
	}

	return 0;
}
