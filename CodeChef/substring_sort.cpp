//http://codeforces.com/contest/988/problem/B

#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<map>
    using namespace std;

vector<pair<int, string> > v;
int n;

bool compare(pair<int,string> p1, pair<int, string> p2 ){
    return p1.first<p2.first;
}

bool check(string s1, string s2){
    for(int i=0;i<s2.length();i++){
        if(s2[i]==s1[0]){
            bool flag=1;
            for(int j=0;j<s1.length();j++){
                if(s2[i+j]!=s1[j]){
                    flag=0;
                }
            }
            if(flag){
                    return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(make_pair(s.length(),s));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n-1;i++){
        if(!check(v[i].second,v[i+1].second)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i=0;i<n;i++){
        cout << v[i].second << endl;
    }
    return 0;
}
