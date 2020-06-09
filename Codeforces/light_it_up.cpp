//http://codeforces.com/contest/1000/problem/B

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
//#include <function>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n,m;
vector<int> lamp, odd, even, lampS; // even on // odd off

int light(){
    int res = even[n];
    for(int i = 0; i <= n + 1; i++){
        int sum = 0;            // n-i
        if(i == 0){
            if(lampS[i] + 1 == lampS[i + 1]){
                    continue;
            }
            sum = 1 + odd[n] - odd[i];
        }else if(i == n + 1){
            if(lampS[i - 1] + 1 == m){
                continue;
            }
            if(i % 2){
                //cout <<"YES ";
                sum = even[n] - 1;
            }else{
                //cout << "NO ";

                sum = even[n] + 1;
            }
        }else{
            if(lampS[i] - 1 == lampS[i - 1] && lampS[i] + 1 == lampS[i + 1]){
                    continue;
            }
            if(i % 2){
                //cout <<"YES ";
                sum = even[i] - 1 + odd[n] - odd[i - 1];
            }else{
                //cout << "NO ";

                sum = even[i - 1] + 1 + odd[n] - odd[i - 1];
            }
        }
        res = max(res, sum);
        //cout << i << " " << sum << " " << res << endl;
    }
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    lamp.resize(n + 2 + 1);
    lampS.resize(n + 2 + 1);
    odd.resize(n + 1 + 1,0);
    even.resize(n + 1 + 1,0);
    lampS[n + 1] = m;
    lampS[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> lampS[i];
    }

    for(int i = 0; i < n + 1; i++){
        lamp[i] = lampS[i+1] - lampS[i];
    }
    even[0] = even[1] = lamp[0];
    odd[0] = 0;
    odd[1] = lamp[1];
    for(int i = 2; i < n + 2; i ++){
        if(i % 2){
            odd[i] = odd[i-2] + lamp[i];
            even[i] = even[i-1];
        }else{
            even[i] = even[i-2] + lamp[i];
            odd[i] = odd[i-1];
        }
    }

    /*for(int i = 0; i <= n + 1; i++){
        cout << lampS[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= n; i++){
        cout << even[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= n; i++){
        cout << odd[i] << " ";
    }
    cout << endl;*/
    cout << light();
    return 0;
}
