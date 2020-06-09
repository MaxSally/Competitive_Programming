//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC15/ORANGE_L15P03/statement
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

const int N = 200005;
bool a[N];
pii segmentTree[4 * N];

void buildTree(int left, int right, int ind){
    if(left == right){
//        segmentTree[ind].first = (a[left]? 1: 0);
//        segmentTree[ind].second = (a[left]? 0: 1);
        segmentTree[ind] = (a[left] ? mp(1, 0) : mp(0, 1));
        return;
    }
    int mid = (left + right)/2;
    buildTree(left, mid, 2 * ind + 1);
    buildTree(mid + 1, right, 2 * ind + 2);
    pii b = segmentTree[2 * ind + 1];
    pii c = segmentTree[2 * ind + 2];
    segmentTree[ind].first = c.first + max(0, b.first - c.second);
    segmentTree[ind].second = b.second + max(0, c.second - b.first);
}

void update(int left, int right, int ind, int pos){
    if(pos > right || pos < left) return;
    if(left == right){
        if(pos == left){
            a[left] = !a[left];
            segmentTree[ind].first = (a[left]? 1: 0);
            segmentTree[ind].second = (!a[left]? 1: 0);
        }
        return;
    }
    int mid = (left + right)/2;
    update(left, mid, 2 * ind + 1, pos);
    update(mid + 1, right, 2 * ind + 2, pos);
    pii b = segmentTree[2 * ind + 1];
    pii c = segmentTree[2 * ind + 2];
    segmentTree[ind].first = c.first + max(0, b.first - c.second);
    segmentTree[ind].second = b.second + max(0, c.second - b.first);
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    rep(ii, 1, 10){
        int n; cin >> n;
        fill(a, a + n + 1, 0);
        int h = (int)ceil(log2(n));
        int szTree = 2 * ((int)pow(2, h)) - 1;
        rep(i, 0, n - 1){
            char c; cin >> c;
            a[i] = (c == '(');
        }
        buildTree(0, n - 1, 0);
        //debuga1(segmentTree, 0, szTree - 1);
        int q; cin >> q;
        cout << "Test " << ii << ":" << "\n";
        while(q--){
            int x; cin >> x;
            if(x == 0){
                if(segmentTree[0].first == 0 && segmentTree[0].second == 0){
                    cout << "YES" << "\n";
                }else{
                    cout << "NO" << "\n";
                }
                //debuga1(segmentTree, 0, szTree - 1);
            }else{
                x--;
                update(0, n - 1, 0, x);
            }
        }
    }
    return 0;
}
