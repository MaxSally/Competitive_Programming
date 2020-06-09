//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=602

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


int main(){
    freopen("input.txt","r",stdin);
    int n, m, c, cnt;
    cnt = 0;
    while(1){
        cnt++;
        cin >> n >> m >> c;
        if(n == 0){
            break;
        }
        int maxConsumption = 0;
        int currentConsumption = 0;
        vector<int> power;
        vector<bool> states;
        states.resize(n + 1, 0);
        power.resize(n + 2);
        for(int i = 1; i <= n; i++){
            cin >> power[i];
        }
        bool flag = false;
        for(int i = 0; i < m; i++){
            int b;
            cin >> b;
            if(states[b]){
                currentConsumption -= power[b];
            }else{
                currentConsumption += power[b];
                if(currentConsumption > c){
                    flag = true;
                }
                maxConsumption = max(maxConsumption, currentConsumption);
            }
            states[b] = !states[b];
        }
        cout << "Sequence " << cnt << endl;
        if(flag){
            cout << "Fuse was blown." << endl << endl;
        }else{
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxConsumption << " amperes." << endl << endl;
        }
    }
    return 0;
}

