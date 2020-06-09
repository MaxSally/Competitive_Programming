//https://www.hackerearth.com/fr/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/little-deepu-and-array/
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

const int N = 100005;

struct triad{
    int left, right, id;
};

int a[N];
vii b, ans;

void buildTree(vector<triad> &segment, vi &lazy, int left, int right, int ind){
    if(left == right){
        segment[ind].left = segment[ind].right = b[left].first;
        lazy[ind] = 0;
        segment[ind].id = b[left].second;
        return;
    }
    int mid = (left + right)/2;
    buildTree(segment, lazy, left, mid, 2 * ind + 1);
    buildTree(segment, lazy, mid + 1, right, 2 * ind + 2);
    segment[ind].left = segment[2 * ind + 1].left;
    segment[ind].right = segment[2 * ind + 2].right;
    segment[ind].id = -1;
}

void update(vector<triad> &segment, vi &lazy, int left, int right, int ind, int tar){
    if(left > right) return;
    if(lazy[ind] > 0){
        segment[ind].left -= lazy[ind];
        segment[ind].right -= lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(tar >= segment[ind].right) return;
    if(tar < segment[ind].left){
        segment[ind].left--;
        segment[ind].right--;
        if(left != right){
            lazy[2 * ind + 1]++;
            lazy[2 * ind + 2]++;
        }
        return;
    }
    int mid = (left + right)/2;
    update(segment, lazy, left, mid, 2 * ind + 1, tar);
    update(segment, lazy, mid + 1, right, 2 * ind + 2, tar);
    segment[ind].left = segment[2 * ind + 1].left;
    segment[ind].right = segment[2 * ind + 2].right;
}

void finalRun(vector<triad> &segment, vi &lazy, int left, int right, int ind){
    if(lazy[ind] > 0){
        segment[ind].left -= lazy[ind];
        segment[ind].right -= lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(left == right){
        ans.pb(mp(segment[ind].id, segment[ind].left));
        return;
    }
    int mid = (left + right)/2;
    finalRun(segment, lazy, left, mid, 2 * ind + 1);
    finalRun(segment, lazy, mid + 1, right, 2 * ind + 2);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    rep(i, 0, n - 1){
        cin >> a[i];
        b.pb(mp(a[i], i));
    }
    sort(b.begin(), b.end());
    vector<triad> segment;
    vi lazy;
    int h = (int) ceil(log2(n));
    int szTree = 2 * (int) pow(2, h) - 1;
    segment.resize(szTree);
    lazy.resize(szTree, 0);
    buildTree(segment, lazy, 0, n - 1, 0);
    int m; cin >> m;
    while(m--){
        int x; cin >> x;
        update(segment, lazy, 0, n - 1, 0, x);
    }
    finalRun(segment, lazy, 0, n - 1, 0);
    sort(ans.begin(), ans.end());
    foreach(v, ans){
        cout << v.second << " ";
    }
    return 0;
}

