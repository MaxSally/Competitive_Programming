//http://www.spoj.com/problems/KOZE/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
    using namespace std;

vector< vector<char> > matrix;
vector< vector<bool> > visited;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int res[]={0,0};//first is sheep
int n,m;
void BFS(int xx,int yy){
    queue< pair<int, int> > process;
    int sumSheep = 0;
    int sumWolf = 0;
    process.push(make_pair(xx,yy));

    while (!process.empty()){
        int x1=process.front().first;
        int y1=process.front().second;
        process.pop();
        if(matrix[x1][y1]=='v'){
            sumWolf++;
        }else if(matrix[x1][y1]=='k'){
            sumSheep++;
        }

        for(int i = 0 ; i < 4 ; i++){
            int x2,y2;
            x2 = x1 + dx[i];
            y2 = y1 + dy[i];

            if(x2>=0 &&  x2< n && y2>= 0 && y2 < m && matrix[x2][y2] != '#' && visited[x2][y2] == 0){
                visited[x2][y2] = 1;

                process.push(make_pair(x2,y2));


            }



        }


    }
    if(sumSheep>sumWolf){
        res[0]+=sumSheep;
    }else{
        res[1]+=sumWolf;
    }
}

int main(){
    freopen("sheep.txt","r",stdin);
    cin >> n >> m;
    matrix.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++){
        matrix[i].resize(m);
        visited[i].resize(m);
        for(int j=0;j<m;j++){
            visited[i][j]=0;
            cin >> matrix[i][j];
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }*/
    int x,y;
    x=0;
    y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && matrix[i][j]!='#'){
                visited[i][j]=1;
                BFS(i,j);

            }
        }
    }


    cout << res[0] << " " << res[1];


    return 0;
}
