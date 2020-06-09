#include<vector>
#include<stack>
#include<stdio.h>
#include<iostream>
    using namespace std;

vector< vector<char> > level;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r1,c1,r2,c2;
stack< pair<int ,int> > process;
int n,m;
bool DFS(){
    process.push(make_pair(r1,c1));
    level[r1][c1]='X';
    while(!process.empty()){
        int x=process.top().first; // x->n y -> m;
        int y=process.top().second;
        process.pop();

        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>0 && x1<=n && y1>0 && y1<=m){
                if(x1==r2 && y1==c2&& level[x1][y1]=='X'){
                    return true;
                }
                else if(level[x1][y1]=='.'){
                    process.push(make_pair(x1,y1));
                    level[x1][y1]='X';
                }
            }

            /*
            if(x1==r2 && y1==c2&& level[x1][y1]=='X'){
                return true;
            }else if(x1==r2 && y1==c2&& level[x1][y1]=='.'){
                process.push(make_pair(x1,y1));
            }else if(x1>0 && x1<=n && y1>0 && y1<=m && level[x1][y1]=='.'){
                process.push(make_pair(x1,y1));

            }
            */

        }
        /*for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){
                cout << level[i][j];
            }
            cout << endl;
        }
        cout << endl;*/

    }
    return false;

}

int main(){
    //freopen("ice_cave_540C.txt","r",stdin);

    cin >> n >> m;


    level.resize(n+1);
    for(int i=1;i<=n;i++){

        level[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin >> level[i][j];

        }
    }
    cin >> r1 >> c1>>r2>>c2;
    if(DFS()==true){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
