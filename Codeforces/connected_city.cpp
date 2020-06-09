//http://codeforces.com/problemset/problem/475/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;
int n,m;

vector<char> vecN,vecM;

bool BFS(){
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<vector<bool> > visited;

            visited.resize(n);
            for(int h=0;h<n;h++){
                visited[h].resize(m,0);
            }
            int cnt=0;
            q.push(make_pair(i,j));
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                int x1,y1;

                x1=-1;
                y1=-1;
                q.pop();


                if(vecN[x]=='>' && y+1<m){
                    y1=y+1;
                }else if(vecN[x]=='<' && y-1>=0){
                    y1=y-1;
                }
                if(y1!=-1 && visited[x][y1]==0){
                    q.push(make_pair(x,y1));
                    visited[x][y1]=1;
                    cnt++;
                }
                if(vecM[y]=='v' && x+1<n){
                    x1=x+1;
                }else if(vecM[y]=='^' && x-1>=0){
                    x1=x-1;
                }

                if(x1!=-1 && visited[x1][y]==0){
                    q.push(make_pair(x1,y));
                    visited[x1][y]=1;
                    cnt++;
                }

            }
            if(cnt!=n*m){
                return false;
            }


        }

    }
    return true;

}



int main(){
    freopen("connected_city.txt","r",stdin);
    cin >> n >> m;


    for(int i=0;i<n;i++){
        char temp;
        cin >> temp;
        if(temp=='<'){
            vecN.push_back('>');
        }else{
            vecN.push_back('<');
        }

    }



    for(int i=0;i<m;i++){
        char temp;
        cin >> temp;
        if(temp=='^'){
            vecM.push_back('v');
        }else{
            vecM.push_back('^');
        }

    }

    if(BFS()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
