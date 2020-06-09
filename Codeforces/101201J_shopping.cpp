//https://codeforces.com/gym/101201/attachments/download/5206/fast-en.pdf
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
ll sparse[20][N], a[N], n;

ll querySparse(int l, int r){
    int k = log2(r - l + 1);
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}


int binarySearch(int left, int right, ll x){
    int mid = left;
    while(left <= right){
        mid = (left + right)/2;
        if(querySparse(left, mid) <= x){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return mid;
}

void createSparse(){
    int h = (int)log2(n);
    rep(i, 1, h){
        rep(j, 0, n - (1 << i)){
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int q; cin >> n >> q;
    rep(i, 0, n - 1){
        cin >> a[i];
        sparse[0][i] = a[i];
    }
    createSparse();
    while(q--){
        ll v;
        int l, r; cin >> v >> l >> r;
        l--; r--;
        while(l <= r){
            v %= a[l];
            if(v == 0) break;
            l = binarySearch(l + 1, r, v);
            //debug(l); debug(v);
        }
        cout << v << '\n';
    }
    return 0;
}
