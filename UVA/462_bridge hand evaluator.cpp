//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=403
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
char suitList[4] = {'S', 'H', 'D', 'C'};
char cardList[3] = {'K', 'Q', 'J'};

int face_point(char c){
    if(c == 'A') return 4;
    if(c == 'K') return 3;
    if(c == 'Q') return 2;
    if(c == 'J') return 1;
    return 0;
}

pair<int,int> suitEvaluator(vector<string> &hand, char card, char suit, int a){
    bool haveCard = 0;
    int cntSuit = 0;
    for(string s: hand){
        if(s[1] != suit) continue;
        cntSuit++;
        if((char)s[0] == card){
            haveCard = 1;
        }
    }
    //cout << card << " " << suit << " " << haveCard << " " << cntSuit << endl;
    pair<int,int> ans;
    if(!haveCard)
        ans.first = 0;
    else if(cntSuit - 1 > a){
        ans.first = 0;
    }else{
        ans.first = -1;
    }
    if(cntSuit == 2){
        ans.second = 1;
    }else if(cntSuit < 2){
        ans.second = 2;
    }else{
        ans.second = 0;
    }
    return ans;
}

bool checkStop(vector<string> &hand, char &d){
    bool allSuit = 1;
    int maxCnt = 0;
    rep(i, 0, 3){
        bool suitStop = 0, king = 0, queen = 0, ace = 0;
        int cntSuit = 0;
        rep(j, 0, (int)hand.size() - 1){
            if(hand[j][1] != suitList[i]) continue;
            cntSuit++;
            char c = hand[j][0];
            if(c == 'A') ace = 1;
            if(c == 'K') king = 1;
            if(c == 'Q') queen = 1;
        }
        if(maxCnt < cntSuit){
            maxCnt = cntSuit;
            d = suitList[i];
        }
        if(ace || (king && ((cntSuit - 1) > 0)) || (queen && ((cntSuit - 1) > 1))){
            suitStop = 1;
        }
        if(!suitStop) allSuit = 0;
    }
    return allSuit;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    string s;
    while(getline(cin, s)){
        vector<string> hand;
        int totalPoint = 0, prePoint = 0;
        for(int i = 0; i < (int)s.length(); i += 3){
            string t = s.substr(i, 2);
            hand.pb(t);
            totalPoint += face_point(t[0]);
            prePoint += face_point(t[0]);
        }
        int subtractSuit = 0, addSuit = 0;
        rep(i, 0, 2){
            rep(j, 0, 3){
                pair<int,int> ans = suitEvaluator(hand, cardList[i], suitList[j], i);
                subtractSuit += ans.first;
                addSuit += ans.second;
            }
        }
        totalPoint += subtractSuit;
        prePoint += subtractSuit;
        totalPoint += addSuit/3;
        if(totalPoint < 14){
            cout << "PASS" << endl;
        }else{
            char c;
            if(checkStop(hand, c) && prePoint >= 16){
                cout << "BID NO-TRUMP" << endl;
            }else{
                cout << "BID " << c << endl;
            }
        }
        //debug(addSuit);
        //debug(totalPoint);
    }
    return 0;
}

