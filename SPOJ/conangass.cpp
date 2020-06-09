//https://www.spoj.com/problems/CONANGSS/vn/
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
#define inf (ll) (1e18 + 9)
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

const int N = 20005;
ll a[N];

struct quad{
    ll left, right, sum, ans;
};

quad segmentTree[4 * N];

void buildTree(int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = {a[left], a[left], a[left], a[left]};
        return;
    }
    int mid = (left + right)/2;
    buildTree(left, mid, 2 * ind + 1);
    buildTree(mid + 1, right, 2 * ind + 2);
    quad b = segmentTree[2 * ind + 1], c = segmentTree[2 * ind + 2];
    segmentTree[ind] = {max(b.left, c.left + b.sum), max(b.right + c.sum, c.right), b.sum + c.sum, max(max(b.ans, c.ans), b.right + c.left)};
}

quad maxQuery(int left, int right, int ind, int leftQ, int rightQ){
    if(right < left) return {-inf, -inf, -inf, -inf};
    if(right < leftQ || rightQ < left)return {-inf, -inf, -inf, -inf};
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    quad b = maxQuery(left, mid, 2 * ind + 1, leftQ, rightQ), c = maxQuery(mid + 1, right, 2 * ind + 2, leftQ, rightQ);
    return {max(b.left, c.left + b.sum), max(b.right + c.sum, c.right), b.sum + c.sum, max(max(b.ans, c.ans), b.right + c.left)};;
}

void singleUpdate(int left, int right, int ind, int pos, ll value){
    if(right < left || right < pos || pos < left) return;
    if(left == pos && right == pos){
        a[pos] += value;
        segmentTree[ind] = {a[pos], a[pos], a[pos], a[pos]};
        return;
    }
    int mid = (left + right)/2;
    singleUpdate(left, mid, 2 * ind + 1, pos, value);
    singleUpdate(mid + 1, right, 2 * ind + 2, pos, value);
    quad b = segmentTree[2 * ind + 1], c = segmentTree[2 * ind + 2];
    segmentTree[ind] = {max(b.left, c.left + b.sum), max(b.right + c.sum, c.right), b.sum + c.sum, max(max(b.ans, c.ans), b.right + c.left)};
}

void printSegment(int szTree){
    rep(i, 0, szTree - 1){
        cout << segmentTree[i].ans << " ";
    }
    cout << endl;
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    fill(a, a + n, 0);
    int h = (int)ceil(log2(n));
    int szTree = 2 * (int)pow(2, h) - 1;
    buildTree(0, n - 1, 0);
    while(m--){
        char c;
        int x, y; cin >> c >> x >> y;
        x--; y--;
        if(c == 'U'){
            int v; cin >> v;
            rep(i, x, y){
                singleUpdate(0, n - 1, 0, i, v);
            }
            //update(segmentTree, lazy, 0, n - 1, 0, x, y, v);
        }else{
            cout << maxQuery(0, n - 1, 0, x, y).ans << endl;
        }
        //printSegment(segmentTree, szTree);

    }
    return 0;
}
