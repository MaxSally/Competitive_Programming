//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include<vector>
#include<stdio.h>
#include<iostream>
#include<queue>
    using namespace std;
vector< vector<int> > tree;
vector<bool>  visited,girl;

int n,q;

int BFS(){
    queue<int> process;
    process.push(1);
    int res=1001;

    while(!process.empty()){

        bool boole=0;
        int node=process.front();
        visited[node]=1;
        process.pop();

        int temp=tree[node].size();
        for(int i=0;i<temp;i++){

            if(visited[tree[node][i]]==0){
                process.push(tree[node][i]);

            }
            if(girl[tree[node][i]]==1){

                boole=1;
                if(res>tree[node][i]){
                    res=tree[node][i];
                }

            }


        }

        if(boole==1){
            break;
        }


    }
    return res;
}

int main(){
    freopen("bishu_gf.txt","r",stdin);


    cin >>n;
    girl.resize(n+1,0);
    visited.resize(n+1,0);
    tree.resize(n+1);
    for(int i=0;i<n-1;i++){
        int temp, temp1;
        cin >> temp >> temp1;
        tree[temp].push_back(temp1);
        tree[temp1].push_back(temp);
    }

    cin >> q;

    for(int i=1;i<=q;i++){
        int temp;
        cin >> temp;
        girl[temp]=1;
    }


    cout << BFS();


    return 0;
}
