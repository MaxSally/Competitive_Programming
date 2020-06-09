//http://codeforces.com/contest/913/problem/D

/*
* Author : Max Nguyen
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
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define left tuyiuoi
#define right fgjhkj
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

struct triad{
    int x, y, z;
    triad(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

vector<triad> a;
int n, t;
VI ans;


bool compare(triad b, triad c){
    if(b.y == c.y){
        return b.x > c.x;
    }
    return b.y < c.y;
}

int bs(){
    int left, right;
    left = 1;
    right = n;
    int res = 0;
    while(left <= right){
        //cout << left << " " << right << endl;
        int mid = (left + right) / 2;
        int time = 0;
        int point = 0;
        int temp = mid;
        int i = 0;
        VI q;
        while(temp--){
            while(a[i].x < mid && i < n){
                i++;
            }
            if(i == n){
                break;
            }
            time += a[i].y;
            q.push_back(a[i].z);
            point++;
            i++;
        }
        if(time > t || temp + 1){
            right = mid - 1;
        }else{
            if(point > res){
                res = point;
                ans.assign(q.begin(), q.end());
                q.clear();
            }
            left = mid + 1;
        }
    }
    return res;
}

int main(){
    io
    //freopen("input.txt","r",stdin);
    cin >> n >> t;
    FOR(i, 0, n, 1){
        int x, y;
        cin >> x >> y;
        triad temp = triad(x, y , i + 1);
        a.PB(temp);
    }
    sort(a.begin(), a.end(), compare);
    /*FOR(i, 0, n, 1){
        cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
    }*/
    cout << bs() << "\n";
    cout << ans.size() << "\n";
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}
