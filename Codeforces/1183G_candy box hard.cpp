//https://codeforces.com/contest/1183/problem/G
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
int n;
pii cnt[N];

bool compare(pii a, pii b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}


int main(){
    io;
    freopen("input.txt", "r", stdin);
    int q; cin >> q;
    while(q--){
        cin >> n;
        rep(i, 0, n){
            cnt[i].first = cnt[i].second = 0;
        }
        rep(i, 1, n){
            int a, f; cin >> a >> f;
            if(f == 1){
                cnt[a].first++;
            }else{
                cnt[a].second++;
            }
        }
        priority_queue<pii, vii, less<pii> > a;
        priority_queue<int, vi, less<int> > pq;
        rep(i, 1, n){
            a.push(mp(cnt[i].first + cnt[i].second, cnt[i].first));
        }
        int cnt = n;
        int maxCandy = 0, maxCandy1 = 0;
        while(a.size()){
            int totalV = a.top().first, value1 = a.top().second;
            //debug(totalV); debug(cnt);
            if(cnt == 0) break;
            if(cnt <= totalV){
                a.pop();
                cnt = min(cnt, totalV);
                maxCandy += cnt;
                if(pq.size() && pq.top() > value1){
                    maxCandy1 += min(cnt, pq.top());
                    pq.pop();
                    pq.push(value1);
                }else{
                    maxCandy1 += min(cnt, value1);
                }
                while((int)a.size() && a.top().first == totalV){
                    pq.push(a.top().second);
                    a.pop();
                }
            }else{
                if((int)pq.size()){
                    maxCandy += cnt;
                    maxCandy1 += min(pq.top(), cnt);
                    pq.pop();
                }else{
                    cnt = totalV + 1;
                }
            }
            cnt--;
        }
        while(cnt > 0 && (int)pq.size()){
            maxCandy += cnt;
            maxCandy1 += min(cnt, pq.top());
            pq.pop();
            cnt--;
        }
        cout << maxCandy << " " << maxCandy1 << endl;
    }
    return 0;
}
