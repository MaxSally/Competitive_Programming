#include <cstring>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include <fstream>
#include<string>
#include<time.h>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;

#define left asdf
#define right asdfdsa
#define ll long long
#define dd double
#define lld long long double

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector< vector<int> > graph;
        vector<int> degree;
        degree.resize(n,0);
        graph.resize(n);
        for(int i = 0; i < n - 1; i++){
            int a = edges[i].first;
            int b = edges[i].second;
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        /*for(int i = 0; i < n; i++){
            cout << degree[i] << " ";
        }
        cout <<endl;*/
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        while(n > 2){
            int temp = q.size();
            for(int i = 0; i < temp; i++){
                int a = q.front();
                q.pop();
                n--;
                for(int j = 0; j < graph[a].size(); j++){
                    int b = graph[a][j];
                    degree[b]--;
                    if(degree[b] == 1)
                        q.push(b);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};

int main(){
    freopen("input.txt","r",stdin);
    Solution s;
    int n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int> > edge;
        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            edge.push_back(make_pair(a,b));
        }
        //cout << "yes" << endl;
        vector<int> ans = s.findMinHeightTrees(n, edge);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
