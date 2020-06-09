//http://codeforces.com/contest/988/problem/C

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<set>
    using namespace std;

struct triple{
    int a,b,c;
};


int n,k;
vector<triple*> v;

bool compare(triple *s1, triple *s2){
    return s1 -> a <s2 -> a;
}

void check(){
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size()-1;i++){
        if(v[i] -> a==v[i+1] -> a){
            cout << "YES" << endl;
            cout << (v[i] -> b) +1<< " " << (v[i] -> c) +1<<endl;
            cout << (v[i+1] -> b) +1<< " " << (v[i+1] -> c) +1<<endl;
            return;
        }
    }
    cout << "NO";
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> k;
    for(int ii=0;ii<k;ii++){
        cin >> n;
        vector<int> temp;
        int sum=0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            sum+=a;
            temp.push_back(a);
        }
        set<int> s;
        for(int i=0;i<n;i++){
            if(s.find(sum-temp[i])==s.end()){
                struct triple *tri = new struct triple;
                tri -> a=sum-temp[i];
                tri -> b=ii;
                tri -> c=i;
                v.push_back(tri);
                s.insert(sum-temp[i]);
            }
        }
    }
    check();

}
