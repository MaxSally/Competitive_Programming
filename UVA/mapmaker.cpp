//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=330
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
int n, r;

struct arr{
    string name;
    vector<ll> listC;
    ll d;
};

vector<arr> listArray;
map<string,int> mpArray;

int main(){
    io
    freopen("input.txt","r",stdin);
    cin >> n >> r;
    int cnt = 0;
    rep(i, 1, n){
        string t; ll b, c, d; vector<pair<ll,ll> >bound;
        cin >> t >> b >> c >> d;
        rep(j, 1, d){
            ll l, u; cin >> l >> u;
            bound.pb({l, u});
        }
        vector<ll> listC(d + 1, 0);
        listC[d] = c;
        rrep(i, d - 1, 1){
            listC[i] = listC[i + 1]*(bound[i].second - bound[i].first + 1);
        }
        listC[0] = b;
        rep(i, 1, d){
            listC[0] -= listC[i]*bound[i - 1].first;
        }
        listArray.pb({t, listC, d});
        //debuga1(listC, 0, d);
        mpArray.insert(pair<string,int>(t, cnt));
        cnt++;
    }
    rep(i, 1, r){
        string t;
        cin >> t;
        int ind = mpArray[t];
        arr &ar = listArray[ind];
        int d = ar.d;
        ll address = ar.listC[0];
        cout << ar.name << "[";
        rep(j, 1, d){
            ll temp; cin >> temp;
            cout << temp;
            if(j != d){
                cout << ", ";
            }
            address += ar.listC[j]*temp;
        }
        cout << "] = " << address << endl;
        //listArray[ind].address = address;
    }
    return 0;
}

