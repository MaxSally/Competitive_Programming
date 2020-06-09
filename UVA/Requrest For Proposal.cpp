//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1082

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

const int inf = 1e9;

int main(){
    freopen("input.txt","r",stdin);
    int n, p;
    int cnt = 0;
    string trash;
    while(1){
        cin >> n >> p;
        if(n == 0){
            break;
        }
        //cout << n << " " << p << endl;
        cnt++;
        string name;
        double price = 1e9;
        int compliance = 0;
        if(cnt > 1){
            cout << endl;
        }
        getline(cin, trash);
        for(int i = 0; i < n; i++){
            getline(cin,trash);
            //cout << i << " " << trash << endl;
        }
        for(int i = 0; i < p; i++){
            string s;
            double a;
            int b;
            getline(cin, s);
            cin >> a >> b;
            if(b > compliance){
                compliance = b;
                price = a;
                name = s;
            }else if(b == compliance){
                if(a < price){
                    price = a;
                    name = s;
                }
            }
            getline(cin, trash);
            for(int j = 0; j < b; j++){
                getline(cin,trash);
            }
        }
        cout << "RFP #" << cnt << endl;
        cout << name << endl;
    }
    return 0;
}

