//http://codeforces.com/contest/742/problem/D

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int const lim=1005;
int n,m,w;
bool visi[lim];
vector <int> weight, beauty;
vector < vector<int> > graph, group;
vector<int> groupW, groupB;
int dp[lim][lim];

int prepare(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = 0;
        }
    }
}

void dfs(){
    stack<int> s;
    for(int i = 1; i <= n; i++){
        vector<int> temp;
        if(!visi[i]){
            int n1 = group.size();
            visi[i]=1;
            s.push(i);
            while(!s.empty()){
                int a = s.top();
                s.pop();
                temp.push_back(a);
                groupB[n1] += beauty[a];
                groupW[n1] += weight[a];
                for(int j = 0; j < graph[a].size(); j++){
                    int b = graph[a][j];
                    if(!visi[b]){
                        visi[b]=1;
                        s.push(b);
                    }
                }
            }
        }
        group.push_back(temp);
    }
}

void print(){
    for(int i=0;i<group.size();i++){
        for(int j=0;j<=w;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int knapsack(){
    for(int i = 1; i <= group.size(); i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(groupW[i-1] <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-groupW[i-1]] + groupB[i-1]);
            }
            //print();
            for(int k = 0; k < group[i-1].size(); k++){
                int a = group[i-1][k];
                if(weight[a] <= j){
                   dp[i][j] = max(dp[i][j], dp[i-1][j-weight[a]] + beauty[a]);
                }
                //print();
            }
        }
    }
    return dp[group.size()][w];
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m >> w;
    //cout << n << m << w;
    weight.resize(n+1);
    beauty.resize(n+1);
    graph.resize(n+1);
    groupB.resize(n+1,0);
    groupW.resize(n+1,0);
    for(int i = 1; i <= n; i++){
        visi[i]=0;
        cin >> weight[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> beauty[i];
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cout <<"YES";
    prepare();
    dfs();
    cout << knapsack();
    return 0;
}
