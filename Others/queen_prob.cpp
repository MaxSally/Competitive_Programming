#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
    using namespace std;

vector< vector<bool> > visited,matrix;
vector< bool> column;

int n;
int cnt;




void makeDia1(int x,int y,stack< pair< int, int> >&process){
    if(x+1>0 && x+1<=n && y+1>0 && y+1<=n){
        if(visited[x+1][y+1]==0){
            visited[x+1][y+1]=1;
            process.push(make_pair(x+1,y+1));
        }
        makeDia1(x+1,y+1,process);

    }
}
void makeDia2(int x,int y,stack< pair< int, int> > &process){
    if(x+1>0 && x+1<=n && y-1>0 && y-1<=n){
        if(visited[x+1][y-1]==0){
            visited[x+1][y-1]=1;
            process.push(make_pair(x+1,y-1));

        }
        makeDia2(x+1,y-1,process);

    }
}


void backtrack(int node){

    for(int i=1;i<=n;i++){

        if(visited[node][i]==0 && column[i]==0){
            //cout << node << " "<< i << endl;
            stack< pair< int, int> >process;

            visited[node][i]=1;
            matrix[node][i]=1;
            column[i]=1;
            process.push(make_pair(node,i));
            makeDia1(node,i,process);
            makeDia2(node,i,process);
            /*for(int ii=1;ii<=n;ii++){
                cout << column[ii];
            }
            cout << endl << endl;
            for(int ii=1;ii<=n;ii++){

                for(int j=1;j<=n;j++){

                    cout << visited[ii][j];
                }
                cout << endl;
            }
            cout << endl;*/

            if(node==n){

                cnt++;
                //cout << cnt << endl;

            }else{
                backtrack(node+1);
            }

            column[i]=0;
            visited[node][i]=0;
            matrix[node][i]=0;
            //cout << "surprise" << endl;
            while(process.top().first!=node && process.top().second!=i){
                int x=process.top().first;
                int y=process.top().second;
                visited[x][y]=0;
                process.pop();
            }



        }



    }



}

int main(){
    freopen("queen_prob.txt","r",stdin);
    cin >>n;
    visited.resize(n+1);
    matrix.resize(n+1);
    column.resize(n+1);
    for(int i=1;i<=n;i++){
        visited[i].resize(n+1);
        matrix[i].resize(n+1);
        column[i]=0;
        for(int j=1;j<=n;j++){
            matrix[i][j]=0;
            visited[i][j]=0;
        }
    }
    cnt=0;

    backtrack(1);
    cout << cnt;

}
