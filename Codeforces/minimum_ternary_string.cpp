//http://codeforces.com/contest/1009/problem/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

string findMiniTernaryString(){
    string t ="";
    s = "3" + s;
    int n = s.length();
    vector<int> sum0, sum2;
    sum0.resize(n, 0);
    sum2.resize(n, 0);
    int total1 = 0;
    for(int i = 1; i < n; i++){
        int a = s[i] - '0';
        if(a == 1){
            total1++;
            sum2[i] = sum2[i - 1];
            sum0[i] = sum0[i - 1];
        }else if(a == 2){
            sum2[i] = sum2[i - 1] + 1;
            sum0[i] = 0;
        }else if(a == 0){
            sum0[i] = sum0[i - 1] + 1;
            sum2[i] = 0;
        }
    }
    bool flag = true;
    for(int i = 1; i < n - 1; i++){
        int flag0, flag2;
        flag0 = sum0[i + 1] - sum0[i];
        flag2 = sum2[i + 1] - sum2[i];
        if(flag0 < 0){
            while(flag0 < 0){
                flag0++;
                t += "0";
            }
            if(flag){
                flag = false;
                while(total1--){
                    t += "1";
                }
            }
        }else if(flag2 < 0){
            if(flag){
                flag = false;
                while(total1--){
                    t += "1";
                }
            }
            while(flag2 < 0){
                flag2++;
                t += "2";
            }
        }
    }
    if(sum0[n - 1] != 0){
        int a = sum0[n - 1];
        while(a--){
            t += "0";
        }
    }
    if(sum2[n - 1] != 0){
        int a = sum2[n - 1];
        while(a--){
            t += "2";
        }
    }
    if(t[0] -'0' == 2){
        while(total1-- && flag){
            t = "1" + t;
        }
    }else{
        while(total1-- && flag){
            t = t + "1";
        }
    }
    return t;
}

 int main(){
    //freopen("input.txt","r",stdin);
    cin >> s;
    cout << findMiniTernaryString();
 }

