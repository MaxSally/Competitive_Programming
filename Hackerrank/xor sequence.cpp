//https://www.hackerrank.com/challenges/xor-se/problem
#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long value(long long a){
    if(a % 8 == 2 || a % 8 == 3){
        return 2LL;
    }else if(a % 8 == 4 || a % 8 == 5){
        return a + 2;
    }else if(a % 8 == 6 || a % 8 == 7){
        return 0LL;
    }else{
        return a;
    }
}

// Complete the xorSequence function below.
long long xorSequence(long long l, long long r) {
    //cout << value(l - 1) << " " << value(r) << endl;
    return (value(r)^value(l - 1));
}

int main(){
    freopen("input.txt","r",stdin);
    int q;
    cin >> q;
    vector<long long> sum(100, 0LL);
    for(int i = 1; i < 100; i++){
        sum[i] = sum[i - 1] ^ (value(i));
        cout << sum[i] << " ";
    }
    cout << endl;
    while(q--){
        ll n, m;
        cin >> n >> m;
        cout << xorSequence(n, m) << endl;
    }
    return 0;
}
