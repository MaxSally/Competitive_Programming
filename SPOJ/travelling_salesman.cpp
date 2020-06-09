//http://www.spoj.com/problems/PESADA04/

#include<stdio.h>
#include<iostream>
#include<vector>
    using namespace std;

int dp[20][20];
int f[(1<<18) + 5][20];
int n;

void dynamics(int start){
    for(int i=0;i<(1<<n)-1;i++){
        for(int j=0;j<n;j++){
            f[i][j]=1e9;
        }
    }
    f[1<<start][start]=0;
    for(int setN=1;setN<(1<<n);setN++){
        if(__builtin_popcount(setN)!=1){
            for(int cur=0;cur<n;cur++){
                if(((setN & (1<<cur))>0) && cur!=start ){
                    int minN=1e9;
                    for(int prev=0;prev<n;prev++){
                        if(prev !=cur && (setN & (1<<prev))>0){
                            int temp =f[setN-(1<<cur)][prev]+dp[prev][cur];
                            if(temp<minN){
                                minN=temp;
                            }
                        }
                    }
                    f[setN][cur]=minN;
                }
            }
        }
    }

}

void print(){
    for(int i=0;i<(1<<n)-1;i++){
        for(int j=0;j<n;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> dp[i][j];
        }
    }
    for(int i=0;i<(1<<n)-1;i++){
        for(int j=0;j<n;j++){
            f[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++){
        f[1<<i][i]=0;
    }
    int minN1=1e9;
    for(int start=0;start<n;start++){
        dynamics(start);
        int minN=1e9;
        for(int i=0;i<n;i++){
            if(i!=start){
                int temp=f[(1<<n)-1][i];
                if(minN>temp){
                    minN=temp;
                }
            }
        }
        //cout << minN << endl;
        if(minN1>minN){
            minN1=minN;
        }
    }


    //print();
    cout << minN1;
    return 0;
}
