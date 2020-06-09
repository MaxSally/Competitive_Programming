//http://codeforces.com/problem/743/D

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
    using namespace std;

int n;
long long ans=-1e19;
const int MAXN=(2e5) +5;
long long cost[MAXN];
vector<int> graph[MAXN];
long long sum[MAXN],maxSum[MAXN];


void createSum(int a,int fa){
    sum[a]=cost[a];
    for(int i=0;i<graph[a].size();i++){
        int v=graph[a][i];
        if(v==fa){
            continue;
        }
        createSum(v,a);
        sum[a]+=sum[v];
        /*if( a==8){
            cout  <<sum[a] << endl;
        }*/

    }
}

void createMaxSum(int a,int fa){
    maxSum[a]=sum[a];
    for(int i=0;i<graph[a].size();i++){
        int v=graph[a][i];
        if(v==fa){
            continue;
        }
        createMaxSum(v,a);
        maxSum[a]=max(maxSum[a],maxSum[v]);
    }
}

void DFS(int start, int fa){
    priority_queue<long long> pq;
    for(int i=0;i<graph[start].size();i++){
        int v=graph[start][i];
        if(fa==v){
            continue;
        }
        pq.push(maxSum[v]);
    }
    if(pq.size()>=2){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        ans=max(ans,a+b);
    }
    for(int i=0;i<graph[start].size();i++){
        int v=graph[start][i];
        if(fa==v){
            continue;
        }
        DFS(v,start);
    }

}

void printSum(){
    for(int i=1;i<=n;i++){
        cout << sum[i] << " ";
    }
    cout << endl;
}

void printMaxSum(){
    for(int i=1;i<=n;i++){
        cout << maxSum[i] << " ";
    }
    cout << endl;
}




int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool flag=true;
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(cnt==0){
            if(graph[i].size()!=2){
                if(graph[i].size()==1){
                    cnt++;
                }else{
                    flag=false;
                }
            }
        }else{
            if(graph[i].size()!=2){
                flag=false;
            }
        }

    }
    if(flag){
        cout << "Impossible";
        return 0;
    }
    createSum(1,-1);
    createMaxSum(1,-1);
    //printSum();
    //printMaxSum();
    DFS(1,-1);
    //processAns();
    cout << ans;
    return 0;
}
