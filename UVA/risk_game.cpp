//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;
int graph[25][25];
const int inf=1e9;


void floyd_warshall(){
    for(int k=1;k<=20;k++){
        for(int i=1;i<=20;i++){
            for(int j=1;j<=20;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,test;
    test=0;
    while(cin>>n){
        test++;
        for(int i=1;i<25;i++){
            for(int j=1;j<25;j++){
                if(i==j){
                    graph[i][j]=0;
                }else{
                    graph[i][j]=inf;
                }

            }
        }
        for(int i=0;i<n;i++){

            int temp;
            cin >> temp;
            graph[1][temp]=1;
            graph[temp][1]=1;
        }
        for(int i=2;i<=19;i++){
            cin >> n;
            for(int j=0;j<n;j++){
                int temp;
                cin >> temp;
                graph[i][temp]=1;
                graph[temp][i]=1;
            }
        }
        floyd_warshall();
        int res;
        cin >> res;
        cout << "Test Set #" << test<< endl;
        for(int i=0;i<res;i++){
            int start,finish;
            cin >> start >> finish;
            if(start<10){
                cout << " ";
            }
            cout << start << " to ";
            if(finish<10){
                cout << " ";
            }

            cout << finish << ": " << graph[start][finish]<< endl;


        }
        cout << endl;






    }
    return 0;
}

