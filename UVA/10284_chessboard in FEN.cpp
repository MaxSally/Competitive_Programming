//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=1225
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
bool attack[8][8];
char board[8][8];
int dx[8] = {0, 0, 1, -1, 1, 1 , -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int dxN[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dyN[8] = {2, -2, 2, -2, 1, -1, 1, -1};


void queen(int x, int y){
    attack[x][y] = 1;
    rep(i, 0, 7){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        while(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && board[x1][y1] == '0'){
            attack[x1][y1] = 1;
            x1 += dx[i];
            y1 += dy[i];
        }
    }
}

void rook(int x, int y){
    attack[x][y] = 1;
    rep(i, 0, 3){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        while(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && board[x1][y1] == '0'){
            attack[x1][y1] = 1;
            x1 += dx[i];
            y1 += dy[i];
        }
    }
}

void bishop(int x, int y){
    attack[x][y] = 1;
    rep(i, 4, 7){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        while(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && board[x1][y1] == '0'){
            attack[x1][y1] = 1;
            x1 += dx[i];
            y1 += dy[i];
        }
    }
}

void knight(int x, int y){
    attack[x][y] = 1;
    rep(i, 0, 7){
        int x1 = x + dxN[i];
        int y1 = y + dyN[i];
        if(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8){
            attack[x1][y1] = 1;
        }
    }
}

void pawn(int x, int y, bool blackWhite){// white : 1
    attack[x][y] = 1;
    if(blackWhite)
        y--;
    else
        y++;
    if(y < 0 || y > 7) return;
    if(x - 1 >= 0) attack[x - 1][y] = 1;
    if(x + 1 < 8) attack[x + 1][y] = 1;
}

void king(int x, int y){
    attack[x][y] = 1;
    rep(i, 0, 7){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8){
            attack[x1][y1] = 1;
        }
    }
}

void print(){
    rep(i, 0, 7){
        rep(j, 0, 7){
            cout << attack[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    io
    freopen("input.txt","r",stdin);
    string s;
    while(getline(cin, s)){
        int pos = 0;
        int x, y; x = y = 0;
        rep(i, 0, 7){
            rep(j, 0, 7){
                board[i][j] = '0';
                attack[i][j] = 0;
            }
        }
        while(pos < (int)s.length()){
            if(isdigit(s[pos])){
                x += (s[pos] - '0');
            }else if(s[pos] == '/'){
                y++;
                x = 0;
            }else{
                board[x][y] = s[pos];
                x++;
            }
            pos++;
        }
        rep(i, 0, 7){
            rep(j, 0, 7){
                if((board[i][j] == 'q') || (board[i][j] == 'Q')){
                    queen(i, j);
                }else if((board[i][j] == 'r') || (board[i][j] == 'R')){
                    rook(i, j);
                }else if((board[i][j] == 'b') || (board[i][j] == 'B')){
                    bishop(i, j);
                }else if((board[i][j] == 'n') || (board[i][j] == 'N')){
                    knight(i, j);
                }else if((board[i][j] == 'k') || (board[i][j] == 'K')){
                    king(i, j);
                }else{
                    if(board[i][j] == 'p'){
                        pawn(i, j, 0);
                    }else if(board[i][j] == 'P'){
                        pawn(i, j, 1);
                    }
                }
            }
        }
        int cnt = 0;
        rep(i, 0, 7){
            rep(j, 0, 7){
                if(!attack[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

