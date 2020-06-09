//https://atcoder.jp/contests/abc157/tasks/abc157_e
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

const int N = 500005;
int n;
string s;

void buildTree(vector<int> &segmentTree, int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = 1 << (s[left] - 'a');
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, left, mid, 2 * ind + 1);
    buildTree(segmentTree, mid + 1, right, 2 * ind + 2);
    segmentTree[ind] = segmentTree[2 * ind + 1] | segmentTree[2 * ind + 2];
}

int query(vector<int> &segmentTree, int left, int right, int ind, int leftQ, int rightQ){
    if(right < left || right < leftQ || rightQ < left){
        return 0;
    }
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    int leftNode = query(segmentTree, left, mid, 2 * ind + 1, leftQ, rightQ);
    int rightNode = query(segmentTree, mid + 1, right, 2 * ind + 2, leftQ, rightQ);
    return (leftNode | rightNode);
}

void update(vi &segmentTree, int left, int right, int ind, int pos, char c){
    if(pos > right || pos < left) return;
    if(left == right){
        if(pos == left){
            segmentTree[ind] -= (1 << (s[left] - 'a'));
            s[left] = c;
            segmentTree[ind] += (1 << (s[left] - 'a'));
        }
        return;
    }
    int mid = (left + right)/2;
    update(segmentTree, left, mid, 2 * ind + 1, pos, c);
    update(segmentTree, mid + 1, right, 2 * ind + 2, pos, c);
    segmentTree[ind] = segmentTree[2 * ind + 1] | segmentTree[2 * ind + 2];
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    cin >> n >> s;
    int szTree = 4 * (n + 1);
    vi segmentTree(szTree);
    buildTree(segmentTree, 0, n - 1, 0);
    int m;
    cin >> m;
    while(m--){
        int type; cin >> type;
        if(type == 1){
            int ind; char c; cin >> ind >> c; ind--;
            update(segmentTree, 0, n - 1, 0, ind, c);
        }else{
            int x, y; cin >> x >> y; x--; y--;
            int ans = query(segmentTree, 0, n - 1, 0, x, y);
            int cnt = 0;
            rep(i, 0, 'z' - 'a'){
                if((ans & (1 << i))) cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}
