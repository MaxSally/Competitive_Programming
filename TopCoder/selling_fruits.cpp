//http://community.topcoder.com/stat?c=problem_statement&pm=14507&rd=16850&rm=329618&cr=23169309

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include<string>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double
#define lld long long double

class SellingFruits{
    #define ll long long
    public: int maxDays(int x, int f, int d, int p){
        int dayDollar = (int) d/x;
        if(f >= dayDollar){
            return dayDollar;
        }
        //cout << total << endl;
        ll temp = (ll) d - (ll) f*x;
        return  temp/( (ll)x + (ll) p) + (ll) f;
    }
};

int main(){
    //freopen("input.txt","r",stdin);
    SellingFruits q;
    int t;
        int x, f, d, p;
        cin >> x >> f >> d >> p;
        cout << q.maxDays(x, f, d, p) << endl;
    return 0;
}
