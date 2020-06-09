
//https://www.hackerrank.com/challenges/even-tree/problem

#include<stdio.h>
#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>
    using namespace std;

int n,m;
vector<int> graph[105];
int sum[105];
int tree[105];

void createSum(int a,int fa){
    sum[a]=1;
    for(int i=0;i<graph[a].size();i++){
        int v=graph[a][i];
        if(v==fa){
            continue;
        }
        createSum(v,a);
        sum[a]+=sum[v];
    }
}

/*void createTree(int a, int fa){
    tree[a]=0;
    for(int i=0;i<graph[a].size();i++){
        int v=graph[a][i];
        if(v==fa){
            continue;
        }
        createTree(v,a);
        if(sum[v]%2 == 0){
            tree[a]+=tree[v];
        }
    }

}*/

void printSum(){
    for(int i=1;i<=n;i++){
        cout << sum[i] << " ";
    }
    cout << endl;
}

void printMaxSum(){
    for(int i=1;i<=n;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    createSum(1,-1);
    //createTree(1,-1);
    //printSum();
    //printMaxSum();
    int ans=0;
    /*for(int i=1;i<=n;i++){
        ans=max(ans,tree[i]);
    }*/
    for(int i=2;i<=n;i++){
        if(sum[i]% 2 ==0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}


