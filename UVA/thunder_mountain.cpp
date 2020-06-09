//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1744

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
    using namespace std;
double graph[105][105];
const double inf=1e9;
vector<pair<double,double> > loc;
int n;


void floyd_warshall(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
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
    int test;
    cin >> test;
    for(int ii=1;ii<=test;ii++){

        cin >> n;

        loc.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    graph[i][j]=0;
                }else{
                    graph[i][j]=inf;
                }

            }
        }
        for(int i=0;i<n;i++){
            int temp, temp1;
            cin >> temp >> temp1;
            loc.push_back(make_pair(temp,temp1));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double temp= sqrt((loc[i].first-loc[j].first)*(loc[i].first-loc[j].first)+ (loc[i].second-loc[j].second)*(loc[i].second-loc[j].second));

                if(temp<10.000001){
                    graph[j+1][i+1]=temp;
                    graph[i+1][j+1]=temp;
                }
            }
        }
        floyd_warshall();
        cout << "Case #" <<ii <<":" << endl;
        double res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(res<graph[i][j]){
                    res=graph[i][j];
                }
            }
        }
        if(res==inf){
            cout <<"Send Kurdy" << endl << endl;
        }else{
            cout << fixed << setprecision(4) << res << endl << endl;
        }

    }






    return 0;
}

