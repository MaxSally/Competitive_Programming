#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
    using namespace std;

int main(){
    freopen("african_crossword_90B.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector< vector<char> > a;
    vector< vector<int> > b;

    a.resize(n);
    for(int i=0;i<n;i++){
        a[i].resize(m);
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j];

        }
    }
    b.resize(n);
    for(int i=0;i<n;i++){
        b[i].resize(m);
        for(int j=0;j<m;j++){
            b[i][j]=0;

        }
    }



    for(int i=0;i<n;i++){
        vector<int>c,d;
        c.resize(260, 0);
        d.resize(260, -1);

        for(int j=0;j<m;j++){
            int z=(int)a[i][j];
            c[z]++;
            d[z]=j;
        }

        for(int j=0;j<260;j++){
            if(c[j]==1){
                b[i][d[j]]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        vector<int>c,d;
        c.resize(260, 0);
        d.resize(260, -1);
        for(int j=0;j<n;j++){
            int z=a[j][i];
            c[z]++;
            d[z]=j;
        }

        for(int j=0;j<260;j++){
            if(c[j]==1){
                b[d[j]][i]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==2){
                cout << a[i][j];
            }


        }
    }



    return 0;
}

