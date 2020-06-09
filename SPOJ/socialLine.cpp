//http://www.spoj.com/problems/SOCIALNE/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
    using namespace std;

bool graph[55][55];
bool visited[55];
int cnt,res,id,len;

void BFS(int a){
    visited[a]=1;
    for(int i=0;i<len;i++){
        if(graph[a][i]==1 && visited[graph[a][i]]==1){
            cnt++;
            BFS(graph[a][i]);
        }
    }
}

int main(){
    freopen("socialLine.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        for(int i=0;i<55;i++){

            for(int j=0;j<55;j++){
                graph[i][j]=0;
            }
        }
        string str;
        cin >> str;

        len=str.size();

        for(int i=0;i<len;i++){
            if(str[i]=='Y'){
                graph[0][i]=1;
            }else{
                graph[0][i]=0;
            }
        }
        for(int h=1;h<len;h++){
            cin >> str;
            for(int i=0;i<str.size();i++){
                if(str[i]=='Y'){
                    graph[h][i]=1;
                }else{
                    graph[h][i]=0;
                }
            }
        }
        /*for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                cout << graph[i][j];
            }
            cout << endl;
        }
        cout << endl;*/
        id=0;
        res=0;
        for(int i=0;i<len;i++){
            cnt=0;
            for(int j=0;j<55;j++){
                visited[j]=0;

            }
            cout << "sur" << endl;
            BFS(i);
            if(cnt>res){
                res=cnt;
                id=i;
            }
        }
        cout << id << " " << res << endl;


    }
    return 0;
}
