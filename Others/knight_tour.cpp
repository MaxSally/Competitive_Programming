
#include<stdio.h>
#include<iostream>
#include<vector>
    using namespace std;
vector< vector<bool> > visited;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,-2,2,-2,2,-1,1};
int n,m;
int res=0;

void knight_tour(int x,int y,int total){
    visited[x][y]=1;

    for(int i=0;i<8;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1 && y1>=1 && x1<=n && y1<=m && visited[x1][y1]==0){

            knight_tour(x1,y1,total+1);
        }
    }
    if(total==n*m){
        //cout << res;
        res++;
    }

    visited[x][y]=0;


}


int main(){
    n=4;
    m=3;
    visited.resize(n+1);
    for(int i=1;i<=n;i++){
        visited[i].resize(m+1);
        for(int j=1;j<=m;j++){
            visited[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            knight_tour(i,j,1);
            //cout << endl;
        }
    }

    cout << res;


    return 0;
}
