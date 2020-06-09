//http://codeforces.com/contest/1009/problem/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll const N = 10000000000;
bool b[N] = {};
vector<int> primes;
int maxN, n, m;

int sieve(int bound){
    int _sieve_size = bound + 1;
    b[0] = b[1] = 0;
    memset(b, true, sizeof b);
    for( ll i = 2; i<= _sieve_size; i++){
        if(!b[i])
            continue;
        primes.push_back(i);
        for( ll j = i*i; j<= _sieve_size; j+=i){
            b[j] = 0;
        }
    }
    return (int) primes.size();
}

queue<int> q;

int process(){
    int ans = 0;
    for(int i = 0; i < maxN; i++){
        int a = primes[i];
        ans += (int) ((n - (n % a) - a)/a + 1);
    }

}

 int main(){
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    maxN = sieve(n);
    int pr = process();
    return 0;
 }
