//https://www.hackerrank.com/challenges/winning-lottery-ticket/problem
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

const int N = 0;

int reverseBit(int a){
    int ans = 0;
    for(int i = 0; i < 10; i++){
        if((a >> (i + 1)) == 0){
            ans += (1 << i);
        }
    }
    return ans;
}

long long winningLotteryTicket(vector<string> tickets) {
    int n = (int)tickets.size();
    vector<long long> freq(1024, 0LL);
    for(int i = 0; i < n; i++){
        string s = tickets[i];
        vector<bool> check(10, 0);
        for(int j = 0; j < s.length(); j++){
            check[s[j] - '0'] = 1;
        }
        //debuga1(check, 0, 9);
        int ans = 0;
        for(int j = 0; j < 10; j++){
            if(check[j]){
                ans += (1 << j);
            }
        }
        //debug(ans);
        freq[ans]++;
    }
    //debug(reverseBit(4));
    long long ans = 0LL;
    for(int i = 0; i < 1023; i++){
        if(freq[i] == 0) continue;
        for(int j = i + 1; j < 1024; j++){
            if((i | j) == 1023){
                ans += freq[i]*freq[j];
            }
        }
    }
    ans += freq[1023]*(freq[1023] - 1)/2LL;
    return ans;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<string> tickets;
    rep(i, 1, n){
        string s; cin >> s;
        tickets.pb(s);
    }
    cout << winningLotteryTicket(tickets);
    return 0;
}
