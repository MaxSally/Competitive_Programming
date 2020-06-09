//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC15/ORANGE_L15P05/statement
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
#define inf (ll) (1e18 + 7)
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

const int N = 200005;
int a[N];

void buildTree(vl &segmentTree, vl &lazy, int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = a[left];
        lazy[left] = 0;
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, lazy, left, mid, 2 * ind + 1);
    buildTree(segmentTree, lazy, mid + 1, right, 2 * ind + 2);
    segmentTree[ind] = min(segmentTree[2 * ind + 1], segmentTree[2 * ind + 2]);
}

ll minQuery(vl &segmentTree, vl &lazy, int left, int right, int ind, int leftQ, int rightQ){
    if(left > right)
        return inf;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(rightQ < left || right < leftQ){
        return inf;
    }
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    ll b = minQuery(segmentTree, lazy, left, mid, 2 * ind + 1, leftQ, rightQ), c = minQuery(segmentTree, lazy, mid + 1, right, 2 * ind + 2, leftQ, rightQ);
    return min(b, c);
}

void update(vl &segmentTree, vl &lazy, int left, int right, int ind, int leftQ, int rightQ, ll value){
    if(left > right) return;
    if(lazy[ind] != 0){
        segmentTree[ind] += lazy[ind];
        if(left != right){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(rightQ < left || right < leftQ)
        return;
    if(leftQ <= left && right <= rightQ){
        segmentTree[ind] += value ;
        if(left != right){
            lazy[2 * ind + 1] += value;
            lazy[2 * ind + 2] += value;
        }
        return;
    }
    int mid = (left + right)/2;
    update(segmentTree, lazy, left, mid, 2 * ind + 1, leftQ, rightQ, value);
    update(segmentTree, lazy, mid + 1, right, 2 * ind + 2, leftQ, rightQ, value);
    segmentTree[ind] = min(segmentTree[2 * ind + 1], segmentTree[2 * ind + 2]);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int h = (int)ceil(log2(n));
    int szTree = 2 * (int)pow(2, h) - 1;
    vl segmentTree(szTree, inf), lazy(szTree, 0);
    rep(i, 0, n - 1){
        cin >> a[i];
    }
    buildTree(segmentTree, lazy, 0, n - 1, 0);
    int m; cin >> m;
    string s;
    //debuga1(segmentTree, 0, szTree - 1);
    while(m--){
        int b, c;
        ll v;
        b = c = v = 0;
        cin >> b >> c;
        getline(cin, s);
        if((int)s.size()){
            int i = 1;
            int turn = 1;
            if(s[i] == '-'){
                turn = -1;
                i++;
            }
            while(i < (int)s.length() && s[i] != ' '){
                v += (s[i] - '0');
                v *= 10;
                i++;
            }
            v /= 10;
            v *= turn;
            if(b <= c)
                update(segmentTree, lazy, 0, n - 1, 0, b, c, v);
            else{
                update(segmentTree, lazy, 0, n - 1, 0, 0, c, v);
                update(segmentTree, lazy, 0, n - 1, 0, b, n - 1, v);
                //debuga1(segmentTree, 0, szTree - 1);
            }
        }else{
            if(b > c){
                int ans = min(minQuery(segmentTree, lazy, 0, n - 1, 0, 0, c), minQuery(segmentTree, lazy, 0, n - 1, 0, b, n - 1));
                cout << ans << endl;
            }else{
                cout << minQuery(segmentTree, lazy, 0, n - 1, 0, b, c) << endl;
            }
        }

    }
    return 0;
}

