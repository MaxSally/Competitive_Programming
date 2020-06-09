//https://codeforces.com/contest/1178/problem/D
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

const int N = 2000;
bool mark[N];
vi prime;
int n, m;
vi ans;

void sieve(){
    fill(mark, mark + N, 1);
    mark[0] = mark[1] = 1;
    rep(i, 2, N){
        if(mark[i]){
            prime.pb(i);
            for(int j = i * i; j < N; j += i){
                mark[j] = 0;
            }
        }
    }
}

bool findSum(int ind, int cnt, int maxCnt){
    if(ind == n){
        return (cnt == maxCnt);
    }
    rep(i, 0, m - 1){
        if(cnt + prime[i] > maxCnt) break;
        if(findSum(ind + 1, cnt + prime[i], maxCnt)){
            ans.pb(prime[i]);
            return 1;
        }
    }
    return 0;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    sieve();
    cin >> n;
    m = (int)prime.size();
    rep(i, 0, m - 1){
        if(prime[i] < n - 1) continue;
        /*vi::iterator it = lower_bound(prime.begin(), prime.end(), minP);
        if(it == prime.end()) continue;
        int ind = it - prime.begin();
        if(ind > 0) ind--;
        int dif;
        if(ind + 1 < m)
            dif = prime[ind + 1] - prime[ind];
        else
            dif = inf;
        int curD = prime[ind] * (n - 2);
        int cnt = 0;
        while(cnt < n - 1 && totalDegree - curD > 0 && totalDegree - curD < N && !mark[totalDegree - curD]){
            curD += dif;
            cnt++;
        }*/
        if(prime[i] > n * (n - 1)/2) break;
        bool done = 0;
        int tar = prime[i] * 2 - 2 * (n - 2);
        pii ans;
        rep(j, 0, m - 1){
            if(prime[j] > tar || prime[j] > n - 1) break;
            rep(k, j, m - 1){
                if(prime[j] + prime[k] > tar || prime[k] > n - 1)break;
                if(prime[j] + prime[k] == tar){
                    done = 1;
                    ans = {prime[j], prime[k]};
                    break;
                }
            }
            if(done) break;
        }
        if(done){
            cout << prime[i] << endl;
            //debug(ans.first); debug(ans.second);
            vii res;
            res.pb(mp(ans.first, 1));
            res.pb(mp(ans.second, 2));
            int turn = 3;
            rep(i, 1, n - 2){
                res.pb(mp(2, turn));
                turn++;
            }
            while(res.size()){
                sort(res.rbegin(), res.rend());
                int x = res[0].first, y = res[0].second;
                res.erase(res.begin());
                rep(j, 0, x - 1){
                    cout << y << " " << res[j].second << endl;
                    res[j].first--;
                }
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}
