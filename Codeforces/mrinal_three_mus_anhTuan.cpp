// https://w...content-available-to-author-only...h.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/mrinal-and-three-musketeers-128f4c52/
//Mrinal and Three Musketeers - Hackerearth
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4004
using namespace std;
vector<int> graph[4004];
int n,m,a,b,ans;
bool visited[MAX];
int cnt[MAX];
void dfs(int src, int par){
	visited[src] = true;
	for(int i = 0 ; i < graph[src].size() ; i++){
		int u = graph[src][i];
		if(!visited[u]){
			dfs(u,src);
		}
		else if(u!= par && par != -1 && find(graph[u].begin(),graph[u].end(),par) != graph[u].end() ){
			int x = cnt[src] + cnt[u] + cnt[par] - 6;
			//cout << "a = "<<src<<" b = "<<u<<" c = "<< par<<endl;
			//cout << "X = "<<x<<endl;
			if(ans==-1){
				ans = x;
			}
			else if(ans>x && x>0){
				ans = x;
			}
		}
	}
}
int main(){
	ans = -1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			dfs(i,-1);
		}
	}
	cout<<ans;

	return 0;
}
