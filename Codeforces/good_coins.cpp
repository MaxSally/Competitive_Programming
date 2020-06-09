//http://codeforces.com/gym/101020/problem/J

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin>> a >> b;
        if(__gcd(a,b)==1){
            cout << "GOOD" << endl;
        }else{
            cout << "NOT GOOD" << endl;
        }
    }

}
