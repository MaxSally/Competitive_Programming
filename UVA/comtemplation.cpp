//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>

        using namespace std;



// x^2-px+q=0;

double process(double p, double q, double n){
    if(n==0){
        return 2;
    }
    if(n==1){
        return p;
    }
    return (p*process(p,q,n-1)- q*process(p,q,n-2));
}

int main(){
    freopen("input.txt","r",stdin);
    while(true){
        double p,q,n;
        cin >> p >> q;
        if(p==0 && q==0){
            break;
        }
        cin >> n;
        cout << process(p,q,n) << endl;
    }
    return 0;
}
