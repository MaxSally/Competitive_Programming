
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
