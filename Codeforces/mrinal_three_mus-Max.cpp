//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/mrinal-and-three-musketeers-128f4c52/

#include<vector>
#include<stdio.h>
#include<iostream>
    using namespace std;
int n,m;
vector<int> matrix[4004];
int visited[4004];
int visitedS[4004];

int res=2e8;

/*bool findN(int a,vector<int> v){
    for(int i=0;i<v.size();i++){
        if(a==v[i]){
            return true;
        }
    }
    return false;
}*/

void DFS(int a, int b,int c){
    visited[a]=1;
    visitedS[a]=1;
    int len=matrix[a].size();
    for(int i=0;i<len;i++){
        int u=matrix[a][i];
        if(!visited[u]){
            DFS(u,a,b);
        }else if(b!=-1 && c!= -1 && u==c && a!=b && b!=c && a!=c){
            int temp=0;
            temp+=matrix[a].size()+matrix[b].size()+matrix[c].size()-6;
            if(temp<res && temp>=0){
                res=temp;
            }

        }
    }

    visited[a]=0;

}

int main(){

    freopen("mrinal_three_mus.txt","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        int temp, temp1;
        scanf("%d",&temp);
        scanf("%d",&temp1);
        matrix[temp].push_back(temp1);
        matrix[temp1].push_back(temp);
    }


    visited[1]=1;
    for(int i=1;i<=n;i++){
        if(visitedS[i]==0){
            DFS(i,-1,-1);
        }

    }


    if(res==200000000){
        printf("-1");
    }else{
        printf("%d",res);
    }

    return 0;
}
