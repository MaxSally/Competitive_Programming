//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=55

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

#define left asdfghxxjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    freopen("input.txt","r",stdin);
    int n;
    int line = 1;
    while(cin >> n){
        //cout << n << endl;
        if(line > 1){
            cout << endl;
        }
        line++;
        map<string, int> mp;
        queue<string> q;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            q.push(s);
            mp[s] = 0;
        }
        for(int i = 0; i < n; i++){
            string s;
            int money, fri;
            cin >> s >> money >> fri;
            //cout << s << endl;
            int keep, give;
            if(fri == 0){
                give = 0;
                keep = money;
            }else{
                give = (int) money / fri;
                keep = money % fri;
            }
            mp[s] += keep - money;
            for(int j = 0; j < fri; j++){
                string t;
                cin >> t;
                mp[t] += give;
            }
        }
        while(!q.empty()){
            cout << q.front() << " " << mp[q.front()] << endl;
            q.pop();
        }
    }
    return 0;
}
