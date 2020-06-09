//https://icpc.kattis.com/problems/speed

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

int const lim = 1005;
double const side = 1e9;
int n;
double d[lim], s[lim];
double leftN = -side;
double rightN = side;
double t;

double findC(){
    double mid;
    while((rightN - leftN) > 1e-9){
        mid = (rightN/(double) 2 + leftN/(double) 2);
        //cout << leftN << " " << mid << " " << rightN << endl;
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += d[i]/(mid + s[i]);
        }
        if(sum < t){
            rightN = mid;
        }else{
            leftN = mid;
        }
        //cout << "YES" << endl;
    }
    return (leftN + rightN)/2.0;
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> d[i] >> s[i];
        leftN = max(leftN, -s[i]);
        //rightN = max(rightN, s[i]);
    }
    cout << fixed << setprecision(9) << findC();
    return 0;
}
