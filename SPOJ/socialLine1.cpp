//http://www.spoj.com/problems/SOCIALNE/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<queue>
    using namespace std;

vector<int> graph[55];
bool visited[55];
int cnt,res,id,len;

int BFS(int a){
    queue<int> q;

    visited[a]=1;


    for(int i=0;i<graph[a].size();i++){

        if(visited[graph[a][i]]==0){

            visited[graph[a][i]]=1;
            q.push(graph[a][i]);
        }
    }
    int length=q.size();
    for(int i=0;i<length;i++){
        int b=q.front();
        q.pop();
        for(int i=0;i<graph[b].size();i++){

            if(visited[graph[b][i]]==0){

                visited[graph[b][i]]=1;
                q.push(graph[b][i]);
            }
        }
    }



    return q.size();
}

int main(){
    freopen("socialLine.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        for(int i=0;i<55;i++){
            graph[i].clear();
        }

        string str;
        cin >> str;

        len=str.size();

        for(int i=0;i<len;i++){
            if(str[i]=='Y'){
                graph[0].push_back(i);
            }
        }
        for(int h=1;h<len;h++){
            cin >> str;

            for(int i=0;i<str.size();i++){
                if(str[i]=='Y'){

                    graph[h].push_back(i);

                }
            }
        }
        /*for(int i=0;i<len;i++){
            for(int j=0;j<graph[i].size();j++){
                cout << graph[i][j];
            }
            cout << endl;
        }
        cout << endl;*/
        id=0;
        res=0;
        for(int i=0;i<len;i++){
            cnt=0;
            //cout << "sur" << endl;
            for(int j=0;j<55;j++){
                visited[j]=0;

            }

            cnt=BFS(i);
            //cout << "not "<<cnt << " "<< res << endl;
            if(cnt>res){
                res=cnt ;
                id=i;
            }
        }
        cout << id << " " << res<< endl;


    }
    return 0;
}
