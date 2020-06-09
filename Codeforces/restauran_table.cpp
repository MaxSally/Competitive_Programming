//http://codeforces.com/contest/828/problem/A

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int n, a, b;
    cin >> n >> a >> b;
    int c = 0;
    int sum = 0;
    while(n--){
        int g;
        cin >> g;
        if(g == 2){
            if(b){
                b--;
            }else{
                sum += g;
            }
        }else{
            if(a){
                a--;
            }else if(b){
                c++;
                b--;
            }else if(c){
                c--;
            }else{
                sum += g;
            }
        }
    }
    cout << sum;
    return 0;
}
