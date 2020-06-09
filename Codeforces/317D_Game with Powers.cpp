//https://codeforces.com/contest/317/problem/D
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
#define foreach(i, a) for(auto i: a)
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

const int N = 40005;
int a[35] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
bool visi[N];
MPII m;

int findGrundy(int mask){
    unordered_set<int> s;
    if(m.find(mask) != m.end()) return m[mask];
    rep(i, 1, 29){
        if(mask & (1 << i)){
            int newMask = mask;
            for(int j = i; j <= 29; j += i){
                newMask &= ~(1 << j);
            }
            s.insert(findGrundy(newMask));
        }
    }
    rep(i, 0, 30){
        if(s.find(i) == s.end()){
            return (m[mask] = i);
        }
    }
    return 31;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int ans = 0, tot = 0;
    /*rep(i, 1, 29){
        int temp = findGrundy((1 << i) - 1);
        if(a[i] != temp){
            debug(i);
            a[i] = temp;
        }
    }
    debuga1(a, 0, 29);*/
    mem(visi, 0);
    rep(i, 2, (int)sqrt(n)){
        if(visi[i]) continue;
        ll j = i;
        int cnt = 0;
        while(j <= n){
            cnt++;
            if(j < N){
                visi[j] = 1;
            }
            j = j * i;
        }
        if(cnt == 1) continue;
        tot += cnt;
        ans ^= a[cnt];
    }
    //debug(ans);
    if((n - tot) & 1){
        ans ^= 1;
    }
    cout << ((ans > 0)? "Vasya": "Petya");
    return 0;
}

