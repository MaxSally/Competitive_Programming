//http://www.spoj.com/problems/KNAPSACK/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
    using namespace std;

int s,n;
vector<pair<int,int> > a;
vector<vector<int> > v;

int maxN(int c,int b){
    if(c>b)
        return c;
    return b;
}


void findV(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(a[i].first > j){
                v[i][j]=v[i-1][j];
            }else{
                v[i][j]=max(v[i-1][j],v[i-1][j-a[i].first]+a[i].second);
            }
        }
    }
}

void print(vector<pair<int,int> > &temp){
    for(int i=0;i<n;i++){
        cout << temp[i].first << " " << temp[i].second <<endl;
    }
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> s >> n;
    v.resize(n+1);
    for(int i=0;i<=n;i++){
        if(i==0){
            v[0].resize(s+1,0);
        }else{
            v[i].resize(s+1);
        }
        v[i][0]=0;
    }

    a.push_back(make_pair(0,0));
    for(int i=0;i<n;i++){
        int b,c;
        cin >> b >> c;
        a.push_back(make_pair(b,c));
    }

    //print(a);
    //cout << endl
    findV();
    /*for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << v[n][s];
    return 0;
}
