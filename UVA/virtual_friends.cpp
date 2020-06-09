//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
    using namespace std;

vector<int> parents,cntV;
map<string,int> name;
int cnt;


int findSet(int u){
    return (parents[u]==u ? u : u = findSet(parents[u]));
}

int unionSet(int a,int b){
    int a1=findSet(a);
    int b1=findSet(b);
    if(a1!=b1){
        parents[b1]=a1;
        cntV[a1]+=cntV[b1];
    }
    return cntV[a1];
}



int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        int n;
        cin >> n;
        cnt=1;
        parents.clear();
        parents.resize(1000000);
        cntV.clear();
        cntV.resize(1000000,1);
        name.clear();
        for(int i=0;i<=1000000;i++){
            parents[i]=i;
        }
        for(int i=0;i<n;i++){
            string a,b;
            cin >> a >> b;
            if(name.find(a)==name.end()){
                name[a]=cnt;
                cnt++;
            }
            if(name.find(b)==name.end()){
                name[b]=cnt;
                cnt++;
            }
            cout << unionSet(name[a],name[b])<< endl;

        }
    }

    return 0;
}





