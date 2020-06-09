//http://www.spoj.com/problems/LASTSHOT/
#include<vector>
#include<iostream>
#include<stdio.h>
#include<stack>
    using namespace std;

vector< vector<int> > matrix;
vector<bool> visited;

int BFS(int start){
    int res=1;
    stack < int > process;
    process.push(start);
    while(!process.empty()){

        int x=process.top();

        process.pop();


        int temp=matrix[x].size();
        for(int i=0;i<temp;i++){
            if(visited[matrix[x][i]]==0){
                res++;
                visited[matrix[x][i]]=1;
                process.push(matrix[x][i]);
            }
        }
    }
    return res;

}

int main(){
    freopen("last_shot.txt","r",stdin);

    int n,m;
    cin >> n>>m;
    visited.resize(n+1,0);
    matrix.resize(n+1);
    for(int i=0;i<m;i++){
        int temp,temp1;
        cin >> temp >> temp1;
        matrix[temp].push_back(temp1);

    }

    int res=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i]=1;
            int temp=BFS(i);
            if(res<temp){
                res=temp;
            }
        }
    }
    cout << res;
    return 0;
}
