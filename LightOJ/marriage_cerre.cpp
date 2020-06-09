//http://lightoj.com/volume_showproblem.php?problem=1011

#include<stdio.h>
#include<iostream>
#include<vector>
    using namespace std;

int cost[20][20];
int f[(1<<18) + 5][20];
int n;

void print(){
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

}

void dynamics(){
    for(int husb=1;husb<=n;husb++){
        for(int setN=1;setN<(1<<n);setN++){
            if(__builtin_popcount(setN) == husb){
                int maxN=0;
                for(int wife=1;wife<=n;wife++){
                    if((setN & (1<<(wife-1)))>0){ //kiem tra xem cai bit cua (1<<wife-1) co bang 1
                        int temp =f[setN-(1<<(wife-1))][husb-1]+cost[wife-1][husb-1];
                        if(temp>maxN){
                            maxN=temp;
                        }
                    }
                }
                f[setN][husb]=maxN;
                //print();
                //cout <<endl;
            }
        }
    }

}




int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> cost[i][j];
            }
        }
        f[0][0]=0;
        int maxN=0;
        dynamics();



        //print();
        cout << "Case " << ii+1 << ": " << f[(1<<n)-1][n] << endl;
    }
    return 0;
}

