#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;

struct triad{
    int start;
    int end;
    int weight;

    triad(int start, int end, int weight){
        this -> start = start;
        this -> end = end;
        this -> weight = weight;
    }
    triad()
    {

    }
};

int n,m;
vector<triad> graph;
vector<int> cost;
const int inf=1e9;



void bellmanF(){

    for(int j=0;j<n;j++){
        bool flag=0;
        for(int i=0;i<m;i++){
            int a=graph[i].start;
            int b=graph[i].end;
            int c=graph[i].weight;
            //cout << a << " " << b <<" " << c << endl;
            if(cost[a] != inf && cost[a]+c<cost[b]){
                //cout<<"Vo day roi"<<endl;
                cost[b]=cost[a]+c;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

bool detect(){
    for(int i=0;i<m;i++){
        int a=graph[i].start;
        int b=graph[i].end;
        int c=graph[i].weight;
        if(cost[a]+c<cost[b]){
            return false;
        }
    }
    return true;
}

int main(){

    cin >> n >> m;
    cost.resize(n,inf);
    for(int i=0;i<m;i++){
        int a, b,c;
        cin >> a >> b >> c;
        triad temp(a,b,c);
        graph.push_back(temp);

    }
    cost[0]=0;
    bellmanF();
    if(detect()==true){
        for(int i=0;i<n;i++){
            cout << cost[i] << " ";
        }
    }else{
        cout << "undefinded";
    }
    return 0;
}
