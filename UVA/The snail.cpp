//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=514


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

const double epsi = 1e-6;

int main(){
    freopen("input.txt","r",stdin);
    double h, u , d, f;
    while(true){
        cin >> h >> u >> d >> f;
        if(h == 0){
            break;
        }
        double iniU = u;
        int day = 0;
        double height = 0;
        while(true){
            day++;

            height += max((db) 0,u);
            if(height > h){
                cout << "success on day " <<  day << endl;
                break;
            }
            height -= d;
            if(height < 0){
                cout << "failure on day " << day << endl;
                break;
            }
            u -= f/100 * iniU;

            //cout << height << " " << u << " " << day << endl;
        }
    }
    return 0;
}
