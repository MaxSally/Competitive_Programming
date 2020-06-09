#include<iostream>
#include<stdio.h>
#include<vector>
    using namespace std;



struct triad{
    int start,term,weight;
    triad(){

    }
    triad(int start, int term, int weight){
        this -> start=start;
        this -> term=term;
        this -> weight=weight;
    }
};

vector<triad> graph;
vector<int> cost,city;
int n,m;
const int inf=1e9;

void bellmanF(){
    for(int i=0;i<=n;i++){
        //bool flag=0;
        for(int j=0;j<m;j++){
            int a=graph[j].start;
            int b=graph[j].term;
            int c=graph[j].weight;
            if(cost[a] != inf && cost[a]+c<cost[b]){
                cost[b]=cost[a]+c;
                //flag=1;
            }
        }
        /*if(flag==0){
            break;
        }*/
    }
}


int main(){
    freopen("extended_traffic.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=1;ii<=t;ii++){
        graph.clear();
        cost.clear();
        city.clear();
        cin >> n;
        city.resize(n+1);
        cost.resize(n+1,inf);
        cost[1]=0;
        for(int i=1;i<=n;i++){
            cin >> city[i];
        }

        cin >> m;
        for(int i=0;i<m;i++){
            int  a,b;
            cin >> a >> b;
            triad temp(a,b,(city[b]-city[a])*(city[b]-city[a])*(city[b]-city[a]));
            graph.push_back(temp);
        }
        int q;
        cin >> q;
        bellmanF();
        cout << "Case " << ii << ":" << endl;
        for(int i=0;i<q;i++){
            int s;
            cin >> s;
            if(cost[s]==inf || cost[s]<3){
                cout << "?" << endl;
            }else{
                cout << cost[s] << endl;
            }
        }


    }
    return 0;
}
