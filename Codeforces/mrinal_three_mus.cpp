//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/mrinal-and-three-musketeers-128f4c52/

#include<vector>
#include<stdio.h>
#include<iostream>
    using namespace std;
int n,m;
vector< vector<int> > matrix;
vector<int> stage,path;
vector<bool> visited;
int res=200000000;

void DFS(int x){
    visited[x]=1;

    for(int i=0;i<matrix[x].size();i++){
        if(!visited[matrix[x][i]]){
            stage[matrix[x][i]]=stage[x]+1;
            path[matrix[x][i]]=x;
            DFS(matrix[x][i]);
        }else{
            if(stage[x]-stage[matrix[x][i]]==2){

                int temp=0;
                temp+=matrix[x].size();
                temp+=matrix[matrix[x][i]].size();
                temp+=matrix[path[x]].size();
                //cout << x << " " << matrix[x][i] << " " << path[x]<< " " << temp-6 << endl;
                if(temp<res){
                    res=temp;
                }
            }
        }
    }
    visited[x]=0;

}

int main(){
    freopen("mrinal_three_mus.txt","r",stdin);
    cin >> n >> m;
    matrix.resize(n+1);
    visited.resize(n+1,0);
    stage.resize(n+1,0);
    path.resize(n+1);
    for(int i=0;i<m;i++){
        int temp, temp1;
        cin >> temp >> temp1;
        matrix[temp].push_back(temp1);
        matrix[temp1].push_back(temp);
    }
    stage[1]=1;
    DFS(1);
    if(res==200000000){
        cout << -1;
    }else{
        cout << res-6;
    }


    return 0;
}
