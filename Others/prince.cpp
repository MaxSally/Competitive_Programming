//

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
    using namespace std;

vector< vector<char> > matrix;
vector< vector<bool> > visited;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int w,h;
int BFS(int xx,int yy){
    int sum=1;
    queue< pair<int, int> > process;
    process.push(make_pair(xx,yy));
    while(!process.empty()){
        int x=process.front().first;
        int y=process.front().second;
        process.pop();
        sum++;
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];

                if(x1>=0 && x1 < w && y1>=0 && y1<h && visited[x1][y1]==0 && matrix[x1][y1]=='.'){

                    visited[x1][y1]=1;

                    process.push(make_pair(x1,y1));
                }

        }
    }
    return sum;



}

int main(){
    freopen("prince.txt","r",stdin);
    int numberOfTestCase;
    cin >> numberOfTestCase;
    for(int number=0;number<numberOfTestCase;number++){
        int x,y;
        cin >> h>> w;
        matrix.resize(w);
        visited.resize(w);
        for(int i=0;i<w;i++){
            matrix[i].resize(h);
            visited[i].resize(h);
            for(int j=0;j<h;j++){
                cin >> matrix[i][j];
                visited[i][j]=0;
                if(matrix[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }


        visited[x][y]=1;
        cout << "Case "<< number+1 << ": " << BFS(x,y) << endl;


    }

    return 0;
}
