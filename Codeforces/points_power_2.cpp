//http://codeforces.com/contest/988/problem/D

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
    using namespace std;

long long n;
vector<long long> res;
set<long long> s;
long long lis[35];

void pow(){
    lis[0]=1;
    for(int i=1;i<=30;i++){
        lis[i]=lis[i-1]*2;
    }

}

void power_of_two(){
    set<long long> ::iterator it;
    int sum=0;
    for(it=s.begin(); it!=s.end();it++){
        for(long long k=0;k<=30;k++){
            int a=*it+lis[k];
            int b=*it-lis[k];
            vector<long long> v;
            v.push_back(*it);
            if(s.find(a)!=s.end()){
                v.push_back(a);
            }
            if(s.find(b)!=s.end()){
                v.push_back(b);
            }
            if(v.size()>sum){
                sum=v.size();
                res=v;
            }
        }

    }
    if(res.empty()){
        it=s.begin();
        cout << 1 << endl << *it;
        return;

    }
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        long long a;
        cin >> a;
        s.insert(a);
    }
    pow();
    power_of_two();
    return 0;
}
