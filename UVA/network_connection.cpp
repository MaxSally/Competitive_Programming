//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<sstream>
    using namespace std;

vector<int> parent;

int findSet(int u){
    while(u!=parent[u]){
        u=findSet(parent[u]);
    }
    return u;
}

void unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    parent[a1]=b1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t=0;
    string s;
    cin >> t;
    getline(cin,s);
    getline(cin,s);
    for(int ii=0;ii<t;ii++){
        int n;
        cin >> n;
        int suc=0;
        int fail=0;
        parent.clear();
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

        s="";
        getline(cin,s);
        while(true){
            getline(cin,s);
            if(s==""){
                break;
            }
            stringstream ss;
            ss << s;
            char a;
            int b,c;
            ss >> a>> b >>c;
            if(a=='c'){
                unionSet(b,c);
            }else{
                if(findSet(b)!=findSet(c)){
                    fail++;
                }else{
                    suc++;
                }
            }
            s="";
        }
        cout << suc << "," << fail << endl;
        if(ii!=t-1){
            cout << endl;
        }
    }


    return 0;
}
