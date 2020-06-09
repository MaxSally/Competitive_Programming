//http://www.bigocoder.com/courses/ORANGE01/ORANGE01_LEC15/ORANGE_L15P02/statement
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

int state(int a){
    if(a == 0) return -1;
    if(a < 0) return 1;
    return 0;
}

void buildTree(vi &segmentTree, int left, int right, int ind){
    if(left == right){
        segmentTree[ind] = state(a[left]);
        return;
    }
    int mid = (left + right)/2;
    buildTree(segmentTree, left, mid, 2 * ind + 1);
    buildTree(segmentTree, mid + 1, right, 2 * ind + 2);
    int b = segmentTree[2 * ind + 1], c = segmentTree[2 * ind + 2];
    if(b == -1 || c == -1){
        segmentTree[ind] = -1;
    }else{
        segmentTree[ind] = b + c;
    }
}

void update(vi &segmentTree, int left, int right, int ind, int pos, int value){
    if(pos > right || pos < left) return;
    if(left == right){
        if(right == pos){
            segmentTree[ind] = state(value);
            a[pos] = value;
        }
        return;
    }
    int mid = (left + right)/2;
    if(pos <= mid){
        update(segmentTree, left, mid, 2 * ind + 1, pos, value);
    }else{
        update(segmentTree, mid + 1, right, 2 * ind + 2, pos, value);
    }
    int b = segmentTree[2 * ind + 1], c = segmentTree[2 * ind + 2];
    if(b == -1 || c == -1){
        segmentTree[ind] = -1;
    }else{
        segmentTree[ind] = b + c;
    }
}

int sumQuery(vi &segmentTree, int left, int right, int ind, int leftQ, int rightQ){
    if(left > rightQ || right < leftQ){
        return 0;
    }
    if(leftQ <= left && right <= rightQ){
        return segmentTree[ind];
    }
    int mid = (left + right)/2;
    int b = sumQuery(segmentTree, left, mid, 2 * ind + 1, leftQ, rightQ);
    int c = sumQuery(segmentTree, mid + 1, right, 2 * ind + 2, leftQ, rightQ);
    if(b == -1 || c == -1){
        return -1;
    }else{
        return b + c;
    }
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int n, k;
    while(cin >> n){
        cin >> k;
        rep(i, 0, n - 1){
            cin >> a[i];
        }
        int h = (int)ceil(log2(n));
        int szTree = 2 * ((int)pow(2, h)) - 1;
        vi segmentTree(szTree, 0);
        buildTree(segmentTree, 0, n - 1, 0);
        //debuga1(segmentTree, 0, szTree - 1);
        string s = "";
        while(k--){
            char c; int i, j;
            cin >> c >> i >> j;
            if(c == 'C'){
                i--;
                update(segmentTree, 0, n - 1, 0, i, j);
            }else{
                i--; j--;
                int b = sumQuery(segmentTree, 0, n - 1, 0, i, j);
                //debug(i); debug(j); debug(b);
                if(b == -1){
                    s += "0";
                }else if(b % 2 == 1){
                    s += "-";
                }else{
                    s += "+";
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}

