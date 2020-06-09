//http://codeforces.com/contest/1004/problem/B

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <set>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n, m;
vector<int> ppl;

bool compare(int a, int b){
    return a < b;
}

bool myfunction(int a, int b){
    return (a == b);
}

void input(){
    cin >> n >> m;
    ppl.push_back(0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ppl.push_back(a - 1);
        ppl.push_back(b);
    }
    /*sort(ppl.begin(), ppl.end(), compare);
    ppl.resize(unique(ppl.begin(), ppl.end()) - ppl.begin());
    /*for(int i = 0; i < ppl.size(); i++){
        cout << ppl[i] << " ";
    }*/
}

string process(){
    string s = "";
    bool flag = 0;
    for(int i = 1; i < ppl.size(); i++){
        int a = ppl[i - 1];
        int b = ppl[i];
        if(b - a == 1){
            if(flag){
                s += "1";
                flag = false;
            }else{
                s += "0";
                flag = true;
            }
            continue;
        }

    }
    return s;
}

int main(){
    freopen("input.txt","r",stdin);
    input();
    bool flag = 0;
    string s;
    for(int i = 0; i < n; i++){
        if(flag){
            s += "1";
            flag = false;
        }else{
            s += "0";
            flag = true;
        }
    }
    cout << s;
    return 0;
}
