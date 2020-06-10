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

const int N = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> simulatedGameWithShuffleTeamPickGroupBaseOnSeatRemaining(){
    vi team;
    vi group;
    SETI groupA, groupB;
    rep(i, 0, 12){
        team.pb(i + 1);
        group.pb((i < 8?1:0));
    }
    shuffle(all(group), rng);
    shuffle(all(team), rng);
    while(!team.empty()){
        int teamEvent = team.back();
        int groupEvent = group.back();
        group.pop_back();
        team.pop_back();
        if(groupEvent){
            groupA.insert(teamEvent);
        }else{
            groupB.insert(teamEvent);
        }
    }
    pair<int,int> ans = {0, 0};
    if(groupA.find(2) != groupA.end() && groupA.find(1) != groupA.end()){
        ans.ff = 1;
    }else if(groupB.find(2) != groupB.end() && groupB.find(1) != groupB.end()){
        ans.ss = 1;
    }
    return ans;
}

pii simulatedGameWithSingleList(){
    vi team;
    rep(i, 0, 12){
        team.pb(i + 1);

    }
    shuffle(all(team), rng);
    int prosperity = -1, ht = -1;
    rep(i, 0, 12){
        if(team[i] == 1){
            prosperity = i;
        }else if(team[i] == 2){
            ht = i;
        }
    }
    return {(prosperity < 8 && ht < 8? 1: 0), (prosperity >= 8 && ht >=8? 1: 0)};
}

int main(){
    io;
    freopen("input.txt", "r", stdin);
    int count = 100000;
    double sameGroupA = 0, sameGroupB = 0;
    rep(i, 1, count){
        pii res = simulatedGameWithShuffleTeamPickGroupBaseOnSeatRemaining();
        sameGroupA += res.ff;
        sameGroupB += res.ss;
    }
    cout << "Random both group and team\n";
    cout << fixed << setprecision(9) << sameGroupA/count << " " << sameGroupB/count << endl;
    //rest
    sameGroupA = 0, sameGroupB = 0;
    rep(i, 1, count){
        pii res = simulatedGameWithSingleList();
        sameGroupA += res.ff;
        sameGroupB += res.ss;
    }
    cout << "Single List methods\n";
    cout << fixed << setprecision(9) << sameGroupA/count << " " <<sameGroupB/count << endl;
    return 0;
}
