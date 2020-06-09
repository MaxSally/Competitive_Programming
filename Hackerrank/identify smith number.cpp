//https://www.hackerrank.com/challenges/identify-smith-numbers/problem
/*
* Author : MaxSally
*/
/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i <= k ; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define inf (int) (1e9 + 7)
#define epsi 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhk
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) rep(i, l, r) cout << a[i] << " "; cout << endl
#define Flag(n) cout << "here " << n << endl
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int N = 0;
vi prime;

bool checkSmith(int n){
    int sumDigi = 0;
    int tempN = n;
    while(tempN){
        sumDigi += tempN % 10;
        tempN /= 10;
        //debug(tempN); debug(sumDigi);
    }
    tempN = n;
    rep(i, 2, (int)sqrt(n)){
        while(tempN > 0 && tempN % i == 0){
            prime.pb(i);
            tempN /= i;
            //debug(i);
        }
    }
    if(tempN > 1){
        prime.pb(tempN);
    }
    int sumPrime = 0;
    rep(i, 0, (int)prime.size() - 1){
        int sumDigiPrime = 0;
        while(prime[i] > 0){
            sumDigiPrime += prime[i] % 10;
            prime[i] /= 10;
        }
        sumPrime += sumDigiPrime;
    }
    //debug(sumDigi); debug(sumPrime);
    if(sumDigi == sumPrime){
        return true;
    }else{
        return false;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    cout << checkSmith(n);
    return 0;
}

