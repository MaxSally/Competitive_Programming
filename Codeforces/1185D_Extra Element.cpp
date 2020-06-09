//https://codeforces.com/problemset/problem/1185/D
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
#define ss second
#define ff first
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

const int N = 200005;
pii a[N];
MPII m;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 0, n - 1){
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(a, a + n);
    /*rep(i, 0, n - 1){
        cout << a[i].ff << " " << a[i].ss << endl;
    }*/
    rep(i, 0, n - 2){
        m[a[i + 1].ff - a[i].ff]++;
    }
    int total = 0, id = -1, mainDif = -1;
    if(m.size() > 3){
        cout << -1;
        return 0;
    }
    //debug(m.size());
    if(m.size() == 3){
        foreach(v, m){
            total += v.ff;
            if(v.ss == n - 3){
                mainDif = max(mainDif, v.ff);
            }
        }
        //debug(total);
        if(mainDif == -1){
            cout << -1;
            return 0;
        }
        if(total == 2 * mainDif){
            int i = 0;
            while(i < n - 2 && (a[i + 1].ff - a[i].ff == mainDif)){
                i++;
            }
            cout << a[i + 1].ss;
        }else{
            cout << -1;
        }
    }else if(m.size() == 2){
        foreach(v, m){
            if(v.ss == n - 2){
                id = v.ff;
                mainDif = max(mainDif, v.ff);
            }
        }
        if(mainDif == -1){
            foreach(v, m){
                if(v.ss == n - 3){
                    mainDif = max(mainDif, v.ff);
                }
            }
            if(mainDif == -1){
                cout << -1;
                return 0;
            }
            int other;
            foreach(v, m){
                if(v.ff == mainDif) continue;
                other = v.ff;
            }
            if(other * 2 == mainDif){
                int i = 0;
                while(i < n - 2 && (a[i + 1].ff - a[i].ff == mainDif)){
                    i++;
                }
                cout << a[i + 1].ss;
                return 0;
            }
        }

        if(a[1].ff - a[0].ff == mainDif && (a[n - 1].ff - a[n - 2].ff) == mainDif){
            int other;
            foreach(v, m){
                if(v.ff == mainDif) continue;
                other = v.ff;
            }
            if(other == 0){
                int i = 0;
                while(i < n - 2 && (a[i + 1].ff - a[i].ff == mainDif)){
                    i++;
                }
                cout << a[i + 1].ss;
            }else{
                cout << -1;
            }
        }else{
            if(a[1].ff - a[0].ff == mainDif){
                cout << a[n - 1].ss;
            }else{
                cout << a[0].ss;
            }
        }
    }else if(m.size() == 1){
        cout << a[0].ss;
    }
    return 0;
}
