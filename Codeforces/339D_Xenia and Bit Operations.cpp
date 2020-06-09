//https://codeforces.com/contest/339/problem/D
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

const int N = 300005;
int a[N];

void buildTree(vi &segmentTree, int left, int right, int ind, bool turn){
    if(left == right){
        segmentTree[ind] = a[left];
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, left, mid, 2 * ind + 1, !turn);
    buildTree(segmentTree, mid + 1, right, 2 * ind + 2, !turn);
    if(turn)
        segmentTree[ind] = segmentTree[2 * ind + 1] | segmentTree[2 * ind + 2];
    else
        segmentTree[ind] = segmentTree[2 * ind + 1] ^ segmentTree[2 * ind + 2];
}

void update(vi &segmentTree, int left, int right, int ind, int pos, int value, bool turn){
    if(right < left || right < pos || pos < left) return;
    if(left == pos && right == pos){
        a[left] = value;
        segmentTree[ind] = a[left];
        return;
    }
    int mid = (left + right)/2;
    update(segmentTree, left, mid, 2 * ind + 1, pos, value, !turn);
    update(segmentTree, mid + 1, right, 2 * ind + 2, pos, value, !turn);
    if(turn)
        segmentTree[ind] = segmentTree[2 * ind + 1] | segmentTree[2 * ind + 2];
    else
        segmentTree[ind] = segmentTree[2 * ind + 1] ^ segmentTree[2 * ind + 2];
}

/*int maxQuery(vi &segmentTree, int left, int right, int ind, int pos, bool turn){
    if(right < left || right < pos || pos < left) return;
    if(left == pos && right == pos){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    int ans;
    if(turn){
        ans = maxQuery(segmentTree, left, mid, 2 * ind + 1, pos, !turn) | maxQuery(segmentTree, mid + 1, right, 2 * ind + 2, leftQ, rightQ, !turn);
    }else{
        ans = maxQuery(segmentTree, left, mid, 2 * ind + 1, leftQ, rightQ, !turn) ^ maxQuery(segmentTree, mid + 1, right, 2 * ind + 2, leftQ, rightQ, !turn);
    }
    return ans;
}*/

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int turn = n & 1;
    n = (1 << n);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    //debuga1(a, 0, (int)a.size() - 1);
    int h = (int)ceil(log2(n));
    int szTree = 2 * (int)pow(2, h) - 1;
    vi segmentTree(szTree, inf);
    buildTree(segmentTree, 0, n - 1, 0, turn);
    while(m--){
        int p, b; cin >> p >> b;
        p--;
        update(segmentTree, 0, n - 1, 0, p, b, turn);
        //debuga1(segmentTree, 0, szTree - 1);
        cout << segmentTree[0] << endl;
    }
    return 0;
}
