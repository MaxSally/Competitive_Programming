//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=499

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct triad{
    int start,term,weight;

    triad(){
    }
    triad(int start,int term,int weight){
        this -> start=start;
        this -> term=term;
        this -> weight=weight;
    }


};

vector<triad> graph;
vector<int> cost;
int n,m;
const int inf=1e9;

bool detectC(){
    for(int j=0;j<n - 1;j++){
        for(int i=0;i<m;i++){
            int a=graph[i].start;
            int b=graph[i].term;
            int c=graph[i].weight;
            if(cost[a] !=inf && cost[a]+c<cost[b]){
                cost[b]=cost[a]+c;
            }
        }
    }
    for(int i=0;i<m;i++){
        int a=graph[i].start;
        int b=graph[i].term;
        int c=graph[i].weight;
        if(cost[a] !=inf && cost[a]+c<cost[b]){
            return true;
        }
    }
    return false;
}

int main(){
    int test;
    cin >> test;
    for(int ii=0;ii<test;ii++){
        cin >> n >>m;
        cost.clear();
        graph.clear();
        cost.resize(n,inf);
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            triad temp(a,b,c);
            graph.push_back(temp);
        }
        cost[0]=0;
        if(detectC()){
            cout << "possible" << endl;
        }else{
            cout << "not possible"<< endl;
        }

    }

    return 0;
}
