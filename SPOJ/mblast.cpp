//http://www.spoj.com/problems/MBLAST
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
    using namespace std;

int v[2005][2005];
int t;
int minN(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

void print(string &a, string &b){
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void findV(string &a, string &b){
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            v[i][j]=minN(minN(v[i-1][j-1]+abs(a[i-1]-b[j-1]),v[i-1][j]+t),v[i][j-1]+t);
        }
    }

}



int main(){
    freopen("input.txt","r",stdin);
    string a,b;
    cin >> a >> b;
    cin >> t;
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            if(i==0){
                v[i][j]=j*t;
            }else if(j==0){
                v[i][j]=i*t;
            }else{
                v[i][j]=1e9;
            }
        }
    }
    findV(a,b);
    //print(a,b);
    cout << v[a.length()][b.length()]-1 << endl;

    return 0;
}
