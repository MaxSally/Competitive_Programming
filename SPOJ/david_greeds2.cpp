#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iomanip>

    using namespace std;

struct triad{
    double startP, endP, weight;
    triad(){

    }
    triad (double startP, double endP,double weight){
        this -> startP=startP;
        this -> endP = endP;
        this -> weight=weight;
    }
};

bool compare(triad a, triad b){
        return a.weight>b.weight;
}

vector<triad> graph;
vector<pair<double, double> > coordinate;
//vector<bool> visited;
vector<vector<int> > path;
int n;

bool check(int a,int b){
    vector<bool> visited1;
    visited1.resize(n,0);
    queue<int> q;
    q.push(a);
    while(q.empty()==false){
        int c=q.front();
        visited1[c]=1;
        q.pop();
        if(c==b){
            return 1;
        }
        for(int i=0;i<path[c].size();i++){
            if(visited1[path[c][i]]==0){
                q.push(path[c][i]);
            }

        }
    }
    return 0;

}


int main(){
    freopen("david_greeds.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int p;
        cin >> n >> p;
        coordinate.clear();
        graph.clear();
        path.clear();
        path.resize(n);
        for(int i=0;i<n;i++){
            double a,b;
            cin >> a >> b;

            coordinate.push_back(make_pair(a,b));

        }


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int c=ceil(p*sqrt((coordinate[i].first-coordinate[j].first)*(coordinate[i].first-coordinate[j].first)+(coordinate[i].second-coordinate[j].second)*(coordinate[i].second-coordinate[j].second)));
                triad temp(i,j,c);

                graph.push_back(temp);
            }
        }
        sort(graph.begin(),graph.end(),compare);
        /*for(int i=0;i<graph.size();i++){
            cout << graph[i].weight << " ";
        }*/
        long long ans=0;
        while(graph.empty()==false){
            double a,b,c;
            a=graph[graph.size()-1].startP;
            b=graph[graph.size()-1].endP;
            c=graph[graph.size()-1].weight;
            //cout << a << " " << b << " " << c << endl;

           if(check(a,b)==0){
                ans+=c;
                path[a].push_back(b);
                path[b].push_back(a);
           }
           graph.pop_back();


        }
        cout << "Scenario #" << ii+1 << ": " << ans % 1000000007 << endl;




    }
    return 0;
}
