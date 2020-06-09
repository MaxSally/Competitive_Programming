//https://www.hackerearth.com/fr/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/bob-and-gcd-d6d86b3b/

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

int k, n;
//vector<int> a;


int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> k >> n;
        //a.resize(n);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a < k){
                sum += (ll) k - a;
                continue;
            }
            int temp = a % k;
            sum += min(temp, k - temp);
        }
        cout << sum << endl;
    }
    return 0;
}
