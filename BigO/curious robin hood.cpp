//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC15/ORANGE_L15P01/statement
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

const int N = 100005;
int a[N];

void buildTree(vi &segmentTree, int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = a[left];
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, left, mid, 2 * ind + 1);
    buildTree(segmentTree, mid + 1, right, 2 * ind + 2);
    segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
}

int sumQuery(vi &segmentTree, int left, int right, int ind, int leftQuery, int rightQuery){
    if(leftQuery <= left && rightQuery >= right){
        return segmentTree[ind];
    }
    if(leftQuery > right || rightQuery < left){
        return 0;
    }
    int mid = (left + right)/2;
    return (sumQuery(segmentTree, left, mid, 2 * ind + 1, leftQuery, rightQuery) + sumQuery(segmentTree, mid + 1, right, 2 * ind + 2, leftQuery, rightQuery));
}

void update(vi &segmentTree, int left, int right, int ind, int pos, int value){
    if(pos < left || right < pos){
        return;
    }
    if(left == right && right == pos){
        segmentTree[ind] = value;
        a[pos]= value;
        return;
    }
    int mid = (left + right)/2;
    if(pos <= mid)
        update(segmentTree, left, mid, 2 * ind + 1, pos, value);
    else
        update(segmentTree, mid + 1, right, 2 * ind + 2, pos, value);
    segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    rep(ii, 1, t){
        int n, q; cin >> n >> q;
        rep(i, 0, n - 1){
            cin >> a[i];
        }
        int h = ceil(log2(n));
        int szTree = 2 * ((int)pow(2, h)) - 1;
        vi segmentTree(szTree, inf);
        buildTree(segmentTree, 0, n - 1, 0);
        cout << "Case " << ii << ":" << endl;
        while(q--){
            int cate; cin >> cate;
            if(cate == 1){
                int i; cin >> i;
                cout << a[i] << endl;
                update(segmentTree, 0, n - 1, 0, i, 0);
            }else if(cate == 2){
                int i, v; cin >> i >> v;
                update(segmentTree, 0, n - 1, 0, i, a[i] + v);
            }else{
                int i, j; cin >> i >> j;
                cout << sumQuery(segmentTree, 0, n - 1, 0, i, j) << endl;
            }
        }

    }
    return 0;
}

