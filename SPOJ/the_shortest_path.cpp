//http://www.spoj.com/problems/SHPATH/en/

#include<vector>
#include<queue>
#include<iostream>
#include<stdio.h>
    using namespace std;

vector< string > name;
vector< vector< pair<int,int> > > vec;
vector<int> costV;
priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;

int findCity(string s){
    for(int i=1;i<=name.size();i++){
        if(name[i]==s){
            return i;
        }
    }
}

makePath(string s){
    while(!pq.empty()){
        int node = pq.top().second;
        int expense=pq.top().first;
        pq.pop();
        for(int i=0;i<vec[node].size();i++){
            if(expense+vec[node][i].first<costV[vec[node][i].second]){
                costV[vec[node][i].second]=expense+vec[node][i].first;
                pq.push(make_pair(costV[vec[node][i].second],vec[node][i].second));
            }

        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("the_shortest_path.txt","r",stdin);
    int s;
    cin >> s;
    for(int i=0;i<s;i++){
        int n;
        cin >>n;

        for(int j=1;j<=vec.size();j++){
            while(!vec[j].empty()){
                vec[j].pop_back();
            }
        }


        name.resize(n+1);
        vec.resize(n+1);
        costV.resize(n+1);
        for(int j=1;j<=n;j++){
            costV[j]=200005;
        }

        for(int j=1;j<=n;j++){
            int p;
            cin >> name[j] >>p;
            for(int h=0;h<p;h++){
                int nr, cost;
                cin >> nr >> cost;
                vec[j].push_back(make_pair(cost,nr));
            }

        }
        int r;
        cin >> r;
        for(int j=0;j<r;j++){
            string start,stop;
            cin >> start >> stop;
            costV[findCity(start)]=0;

            pq.push(make_pair(0,findCity(start)));
            makePath(stop);
            cout << costV[findCity(stop)] << endl;
            for(int h=1;h<=n;h++){
                costV[h]=200005;
            }
        }
    }

    return 0;

}
