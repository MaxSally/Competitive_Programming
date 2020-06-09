//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

vector<vector<pair<int,int> > > vec;
vector<int> cost;
priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;

void makePath(){
    while(!pq.empty()){
        int node = pq.top().second;
        int costN= pq.top().first;
        pq.pop();
        for(int i=0;i<vec[node].size();i++){
            if(costN+vec[node][i].first < cost[vec[node][i].second]){
                cost[vec[node][i].second]=costN+vec[node][i].first;
                pq.push(make_pair(cost[vec[node][i].second],vec[node][i].second));
            }
        }
    }

}




int main(){
    freopen("sending_mail.txt","r",stdin);
    int test;
    cin >> test;
    for(int ii=1;ii<=test;ii++){
        for(int i=0;i<vec.size();i++){
            vec[i].clear();
        }
        vec.clear();
        int n,m,s,t;
        cin >> n >> m >> s >> t;
        vec.resize(n);
        cost.resize(n);
        for(int i=0;i<n;i++){
            cost[i]=2000000005;
        }
        cost[s]=0;

        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            vec[a].push_back(make_pair(c,b));
            vec[b].push_back(make_pair(c,a));
        }

        pq.push(make_pair(0,s));
        makePath();
        int res=cost[t];




        if(res==2000000005){
            cout << "Case #" <<ii << ": unreachable" << endl;
        }else{
            cout << "Case #" <<ii << ": "<< res << endl;
        }



    }
    return 0;
}


