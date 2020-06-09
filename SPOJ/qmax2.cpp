//https://www.spoj.com/problems/QMAX2/
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

const int N = 50005;
int a[N];

void buildTree(vi &segmentTree, vi &lazy, int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = a[left];
        lazy[ind] = 0;
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, lazy, left, mid, 2 * ind + 1);
    buildTree(segmentTree, lazy, mid + 1, right, 2 * ind + 2);
    segmentTree[ind] = max(segmentTree[2 * ind + 1], segmentTree[2 * ind + 2]);
}

void update(vi &segmentTree, vi &lazy, int left, int right, int ind, int leftQ, int rightQ, int value){
    if(right < left) return;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(right < leftQ || rightQ < left) return;
    if(leftQ <= left && right <= rightQ){
        segmentTree[ind] += value;
        if(left != right){
            lazy[2 * ind + 1] += value;
            lazy[2 * ind + 2] += value;
        }
        return;
    }
    int mid = (left + right)/2;
    update(segmentTree, lazy, left, mid, 2 * ind + 1, leftQ, rightQ, value);
    update(segmentTree, lazy, mid + 1, right, 2 * ind + 2, leftQ, rightQ, value);
    segmentTree[ind] = max(segmentTree[2 * ind + 1], segmentTree[2 * ind + 2]);
}

int maxQuery(vi &segmentTree, vi &lazy, int left, int right, int ind, int leftQ, int rightQ){
    if(right < left) return 0;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(right < leftQ || rightQ < left) return 0;
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    return max(maxQuery(segmentTree, lazy, left, mid, 2 * ind + 1, leftQ, rightQ), maxQuery(segmentTree, lazy, mid + 1, right, 2 * ind + 2, leftQ, rightQ));
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fill(a, a + n + 1, 0);
    int h = (int)ceil(log2(n));
    int szTree = 2 * (int)pow(2, h) - 1;
    vi segmentTree(szTree, inf), lazy(szTree);
    buildTree(segmentTree, lazy, 0, n - 1, 0);
    while(m--){
        int q, x, y; cin >> q >> x >> y;
        x--; y--;
        if(q == 0){
            int v; cin >> v;
            update(segmentTree, lazy, 0, n - 1, 0, x, y, v);
        }else{
            cout << maxQuery(segmentTree, lazy, 0, n - 1, 0, x, y) << endl;
        }
    }
    return 0;
}
