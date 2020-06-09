//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<algorithm>
#include<sstream>
    using namespace std;

vector<int> parents;
vector<bool> visited;


int findSet(int u){
    while(u!=parents[u]){
        u=findSet(parents[u]);
    }
    return u;
}

void unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    parents[b1]=a1;
}


int main(){
    freopen("input.txt","r",stdin);
    int t;
    string s;
    cin >> t;
    getline(cin,s);
    getline(cin,s);
    for(int ii=0;ii<t;ii++){
        parents.clear();
        visited.clear();
        char c;
        cin >> c;
        int n=c-'A';
        parents.resize(n+1);
        visited.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parents[i]=i;
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
            char a,b;
            string s1;
            ss >> s1;
            a=s1[0];
            b=s1[1];
            //cout << a << " " << b << endl;
            int a1=a-'A';
            int b1=b-'A';
            //cout << a1 << " " << b1 << endl;
            unionSet(a1,b1);
            //cout << "YES" << endl;
            s="";
        }
        for(int i=0;i<=n;i++){
            int temp=findSet(i);
            //cout << i << " " << temp << endl;
            visited[temp]=1;
        }
        //cout << endl;
        int ans=0;
        for(int i=0;i<=n;i++){
            //cout << i<< " "<<visited[i] << endl;
            ans+=visited[i];
        }
        cout << ans << endl;
        if(ii!=t-1){
            cout << endl;
        }

    }

    return 0;
}


