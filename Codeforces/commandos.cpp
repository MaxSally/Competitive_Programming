//http://www.lightoj.com/volume_showproblem.php?problem=1174

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;

vector<int> costS, costD;
vector<vector<int > > vec;
priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;

void makePath(vector<int> &cost){
    while(!pq.empty()){
        int node = pq.top().second;
        int costN= pq.top().first;
        pq.pop();
        for(int i=0;i<vec[node].size();i++){
            if(costN+1 < cost[vec[node][i]]){
                cost[vec[node][i]]=costN+1;
                pq.push(make_pair(cost[vec[node][i]],vec[node][i]));
            }
        }

    }

}




int main(){
    freopen("commandos.txt","r",stdin);
    int test;
    cin >> test;
    for(int ii=1;ii<=test;ii++){
        int n,r,res;
        cin >> n >> r;
        for(int i=0;i<vec.size();i++){
            vec[i].clear();
        }
        vec.clear();
        vec.resize(n);
        costS.resize(n);
        costD.resize(n);

        for(int i=0;i<r;i++){
            int a,b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int s,d;
        cin >> s >> d;

        for(int i=0;i<n;i++){
            costS[i]=2000000005;
        }
        costS[s]=0;
        pq.push(make_pair(0,s));
        makePath(costS);
        for(int i=0;i<n;i++){
            costD[i]=2000000005;
        }
        costD[d]=0;
        pq.push(make_pair(0,d));
        makePath(costD);
        res=0;
        for(int i=0;i<n;i++){
            if(res<costS[i]+costD[i]){
                res=costS[i]+costD[i];
            }
        }
        cout << "Case " << ii <<": " << res << endl;

    }
    return 0;
}
