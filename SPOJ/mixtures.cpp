//http://www.spoj.com/problems/MIXTURES/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
    using namespace std;

int a[205][205];
int b[205],c[205];
int minN(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

void print(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void findV(int n){
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            for(int k=j;k<i;k++){
                a[j][i]=minN(((c[k]-c[j-1]+100)%100)*((c[i]-c[k]+100)%100)+a[j][k]+a[k+1][i],a[j][i]);

            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    while(cin >> n){
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==j){
                    a[i][j]=0;
                }else if(i+1==j || i-1==j){
                    a[i][j]=b[i]*b[j];
                }else{
                    a[i][j]=1e9;
                }
            }
        }
        c[0]=b[0];
        for(int i=1;i<=n;i++){
            c[i]=b[i]+c[i-1];
        }
        findV(n);
        cout << a[1][n] << endl;
    }


    return 0;
}

