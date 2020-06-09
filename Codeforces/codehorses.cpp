//http://codeforces.com/contest/1000/problem/A

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <queue>
#include <string>
#include <map>
using namespace std;

#define left asdfghjkl
#define right sdfghjk
#define ll long long
#define db double

int n;
map<string, int> oldS, newS;

int total(){
    int sum = 0;
    sum += abs(oldS["S"] - newS["S"]) + abs(oldS["M"] - newS["M"]) + abs(oldS["L"] - newS["L"]);
    sum += abs(oldS["XS"] - newS["XS"]) + abs(oldS["XL"] - newS["XL"]);
    sum += abs(oldS["XXS"] - newS["XXS"]) + abs(oldS["XXL"] - newS["XXL"]);
    sum += abs(oldS["XXXS"] - newS["XXXS"]) + abs(oldS["XXXL"] - newS["XXXL"]);
    return sum/2;
}


int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    oldS["S"] = oldS["M"] = oldS["XS"] = oldS["XXS"] = oldS["XXXS"] = oldS["L"] = oldS["XL"] = oldS["XXL"] = oldS["XXXL"] = newS["S"] = newS["M"] = newS["XS"] = newS["XXS"] = newS["XXXS"] = newS["L"] = newS["XL"] = newS["XXL"] = newS["XXXL"] = 0;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        oldS[temp]++;
    }
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        newS[temp]++;
    }
    cout << total();
}


