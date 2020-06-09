//https://vn.spoj.com/problems/KQUERY/
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

const int N = 30005;
int segmentTree[4 * N], a[N], ans[7 * N], lazy[4 * N];

struct quad{
    int x,y, k, ind;
};

bool compare(quad a, quad b){
    return a.k > b.k;
}

bool compare1(pii a, pii b){
    return a.first > b.first;
}

void buildTree(int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = lazy[ind] = 0;
        return;
    }
    int mid = (left + right)/2;
    buildTree(left, mid, 2 * ind + 1);
    buildTree(mid + 1, right, 2 * ind + 2);
    segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
}

void update(int left, int right, int ind, int pos){
    if(right < left) return;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(pos < left || right < pos) return;
    if(left == pos && right == pos){
        segmentTree[ind] = 1;
        if(left != right){
            lazy[2 * ind + 1] = 1; lazy[2 * ind + 2] = 1;
        }
        return;
    }
    int mid = (left + right)/2;
    if(pos <= mid)
        update(left, mid, 2 * ind + 1, pos);
    else
        update(mid + 1, right, 2 * ind + 2, pos);
    segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
}

int cntQuery(int left, int right, int ind, int leftQ, int rightQ){
    if(right < left) return 0;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left < right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(right < leftQ || rightQ < left) return 0;
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int  mid = (left + right)/2;
    return cntQuery(left, mid, 2 * ind + 1, leftQ, rightQ) + cntQuery(mid + 1, right, 2 * ind + 2, leftQ, rightQ);
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int h = (int)ceil(log2(n));
    int szTree = 2 * (int)pow(2, h) - 1;
    vii cnt;
    rep(i, 0, n - 1){
        cin >> a[i];
        cnt.pb({a[i], i});
    }
    sort(cnt.begin(), cnt.end(), compare1);
    int m; cin >> m;
    vector<quad> b;
    rep(ii, 1, m){
        int x, y, k; cin>> x >>y >> k;
        x--; y--;
        b.pb({x, y, k, ii});
    }
    sort(b.begin(), b.end(), compare);
    int ind = 0;
    buildTree(0, n - 1, 0);
    rep(i, 0, m - 1){
        quad q = b[i];
        //debug(q.k); debug(q.x);
        while(ind < n && cnt[ind].first > q.k){
            //debug(ind);
            update(0, n - 1, 0, cnt[ind].second);
            ind++;
        }
        //debuga1(segmentTree, 0, szTree);
        ans[q.ind] = cntQuery(0, n - 1, 0, q.x, q.y);
        //debug(ans[q.ind]);
    }
    rep(i, 1, m){
        cout << ans[i] << '\n';
    }
    return 0;
}
