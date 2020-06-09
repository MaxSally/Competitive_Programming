//http://www.spoj.com/problems/CAM5/

#include<vector>
#include<iostream>
#include<stdio.h>
#include<queue>
    using namespace std;


bool  visited[100000];

void DFS(int start,vector< vector<int> > &relationship){
    int l=relationship[start].size();
    visited[start]=1;
    for(int i=0;i<l;i++){
        if(visited[relationship[start][i]]==0){
            DFS(relationship[start][i],relationship);
        }

    }
}


int main(){
    //freopen("help_the_team.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int n,e,cnt;
        cnt=0;
        cin >> n >> e;
        vector< vector<int> >  relationship;


        for(int i=0;i<n;i++){
            visited[i]=0;

        }



        relationship.resize(n);
        for(int i=0;i<e;i++){
            int temp, temp1;
            cin >> temp >> temp1;
            relationship[temp].push_back(temp1);
            relationship[temp1].push_back(temp);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                cnt++;
                DFS(i,relationship);
            }

        }
        cout << cnt << endl;

    }
    return 0;
}
