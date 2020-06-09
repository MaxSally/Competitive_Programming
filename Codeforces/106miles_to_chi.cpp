
//https://www.urionlinejudge.com.br/judge/en/problems/view/1655

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
#include<iomanip>

    using namespace std;

struct triad{
    int start,term;
    double weight;
    triad(){

    }
    triad(int start,int term,double weight){
        this -> start= start;
        this -> term = term;
        this -> weight= weight;
    }


};

vector<triad> graph;
vector<double> cost;
int n,m;
const int inf=0;



void bellmanF(){
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<graph.size();j++){
            int a=graph[j].start;
            int b=graph[j].term;
            double c=graph[j].weight;
            if(cost[a]!= (double) inf && cost[a]*c > cost[b] ){
                cost[b]=cost[a]*c;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        cin >> n ;

        if(n==0){
            break;
        }
        cin >> m;
        cost.clear();
        graph.clear();
        cost.resize(n+1,inf);

        for(int i=0;i<m;i++){
            int a,b;
            double c;
            cin >> a >> b >> c;

            c=c/100;
            triad temp(a,b,c);
            triad temp1(b,a,c);
            graph.push_back(temp);
            graph.push_back(temp1);

        }
        cost[1]=1;

        bellmanF();
        cost[n]=cost[n]*100;
        cout << fixed << setprecision(6) << cost[n] << " percent" << endl;


    }


    return 0;
}

