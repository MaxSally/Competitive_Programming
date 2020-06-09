//https://codeforces.com/contest/1187/problem/C
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

const int N = 1005;
int a[N], n, m;
vii lst, odd;

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    mem(a, 0);
    rep(i, 0, m - 1){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1)
            lst.pb(mp(y, z));
        else{
            a[y] = -1;
            odd.pb(mp(y, z));
        }
    }
    int turn = 0;
    vii newLst;
    sort(all(lst));
    while(turn < (int)lst.size()){
        int left = lst[turn].ff, right = lst[turn].ss;
        while(turn + 1 < (int)lst.size() && right >= lst[turn + 1].ff){
            right = max(right, lst[turn + 1].ss);
            turn++;
        }
        newLst.pb(mp(left, right));
        turn++;
    }
    int cur = 1000000;
    if(newLst.size()){
        int firstLeft = newLst[0].ff;
        rep(i, 1, firstLeft - 1){
            int pre = a[i];
            a[i] = cur;
            if(pre == -1) cur--;
        }
    }else{
        rep(i, 1, n){
            int pre = a[i];
            a[i] = cur;
            if(pre == -1) cur--;
        }
    }

    rep(i, 0, (int)newLst.size() - 1){
        int left = newLst[i].ff, right = newLst[i].ss, delta = 0;
        //debug(left); debug(right);
        rep(j, left, right){
            if(a[j] == -1) delta++;
            a[j] = cur;
        }
        cur -= delta;
        int nxtLeft;
        if(i < (int)newLst.size() - 1)
            nxtLeft = newLst[i + 1].ff;
        else
            nxtLeft = n + 1;
        rep(j, right + 1, nxtLeft - 1){
            int pre = a[j];
            a[j] = cur;
            if(pre == -1) cur--;
        }
    }
    /*if(n == 1000 && m == 1000){
        cout << "YES" << endl;
        debuga1(a, 1, n);
    }*/
    foreach(v, odd){
        bool flag = 0;
        rep(j, v.ff, v.ss - 1){
            if(a[j] > a[j + 1]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    debuga1(a, 1, n);
    return 0;
}
