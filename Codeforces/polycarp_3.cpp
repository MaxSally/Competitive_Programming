//http://codeforces.com/contest/1005/problem/D

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
#include <map>
#include <queue>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

string s;

int segment(){
    int cnt = 0;
    int remain = 0;
    int n = s.length();
    bool flag = false;
    for(int i = 0; i < n; i++){
        int temp = (remain + (s[i]-'0'))  % 3;
        //cout << remain << " " << temp<< " ";
        if( temp == remain){
            cnt++;
            remain = 0;
            flag = false;
        }else if(temp == 0){
            cnt++;
            remain = 0;
            flag = false;
        }else{
            if(flag && remain!= 0){
                cnt++;
                remain = 0;
                flag = false;
            }else{
                if(remain)
                    flag = true;
                remain = temp;
            }
        }
        //cout << " " <<flag << " " <<cnt << endl;
    }
    return cnt;
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> s;
    cout << segment();
    return 0;
}
