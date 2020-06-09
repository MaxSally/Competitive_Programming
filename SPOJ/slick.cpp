#include<vector>
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
vector < vector <bool> > matrix,visited;
//vector< int> res;
int res[250*250];


int n,m,cnt;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int DFS(int x, int y){
    stack< pair<int, int> > process;
    visited[x][y] = 1;
    int sum = 0;
    process.push(make_pair(x,y));
    while (!process.empty()){
        int x1=process.top().first;
        int y1=process.top().second;
        process.pop();
        sum++;
        for(int i = 0 ; i < 4 ; i++){
            int x2,y2;
            x2 = x1 + dx[i];
            y2 = y1 + dy[i];
            if(x2>=0 &&  x2< n && y2>= 0 && y2 < m && matrix[x2][y2] == 1 && visited[x2][y2] == 0){
                visited[x2][y2] = 1;
                process.push(make_pair(x2,y2));
            }
        }

    }


    return sum;
}


void print(){
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<visited[i][j]<<" ";
            }
        cout<<endl;
    }
}
int main(){

    int xx;
    while(true){
        cnt=0;
        cin >> n>> m;
        if(n==0 && m==0){
            break;
        }
        matrix.resize(n);
        visited.resize(n);
        for(int i=0;i<n;i++){
            matrix[i].resize(m);
            visited[i].resize(m);
            for(int j=0;j<m;j++){

                visited[i][j]=0;
                cin >> xx;
                matrix[i][j] = xx;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1 && visited[i][j]==0){
                    xx=DFS(i,j);
                    cnt++;

                    res[xx]++;

                }

            }
        }
        cout << cnt << endl;
        int temp=250*250;
        for(int i=0;i<temp;i++){
            if(res[i]!=0){
                cout << i << " "<< res[i] << endl;
                res[i]=0;
            }
        }

    }


    return 0;
}
