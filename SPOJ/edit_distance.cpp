//http://www.spoj.com/problems/EDIST/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
    using namespace std;

int v[2005][2005];
int minN(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

void findV(string &a, string &b){
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1]==b[j-1]){
                v[i][j]=v[i-1][j-1];
            }else{
                v[i][j]=minN(minN(v[i-1][j-1]+1,v[i][j-1]+1),v[i-1][j]+1);
            }
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        string a,b;
        cin >> a >> b;
        for(int i=0;i<=a.length();i++){
            for(int j=0;j<=b.length();j++){
                if(i==0){
                    v[i][j]=j;
                }else if(j==0){
                    v[i][j]=i;
                }else{
                    v[i][j]=1e9;
                }
            }
        }
        findV(a,b);
        cout << v[a.length()][b.length()] << endl;
    }

    return 0;
}
