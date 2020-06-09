//codeforces.com/contest/998/problem/0

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

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    int minN = 1e9;
    int index = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < minN){
            minN = a[i];
            index = i + 1;
        }
    }
    if(n == 1 || (n == 2 && a[0] == a[1])){
        cout << -1;
        return 0;
    }else{
        cout << "1" << endl <<  index;
    }
    return 0;
}
