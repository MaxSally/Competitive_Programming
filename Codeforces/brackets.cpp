//https://open.kattis.com/problems/brackets

#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
    using namespace std;

bool dp[5005][5005][3];
string s;
int n;

int check(char s){
    if(s=='('){
        return 1;
    }else{
        return -1;
    }
}

int checkValidity(int l, int r){
    int sum=0;
    //cout << l << " " << r << endl;
    for(int i=0;i<n;i++){
        //cout << sum << endl;
        if(i<l ||i>r){
            sum+=check(s[i]);
            if(sum<0){
                return -1;
            }
        }else{
            sum-=check(s[i]);
            if(sum<0){
                return -1;
            }
        }
    }
    //cout << sum << endl << endl;
    return sum;
}

/*void determine(){
    n=s.length();
    if(n % 2==1){
        cout << "impossible";
        return;
    }
    if(n==0){
        cout << "possible";
        return;
    }
    int sum=0;
    bool mem=1;
    for(int i=0;i<n;i++){
        sum+=check(s[i]);
        if(sum<0){
            mem=0;
        }
    }
    if(sum==0 && mem){
        cout << "possible";
        return;
    }
    dp.resize(n);
    for(int i=0;i<n;i++){
        dp[i].resize(n+1);
    }
    for(int i=0;i<n;i++){
        dp[i][i]=check(s[i]);
        for(int j=i+1;j<n;j++){
            dp[j][i]=dp[i][j]=dp[i][j-1]+check(s[j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int flag=checkValidity(i,j);
            if(flag==0){
                cout << "possible";
                return;
            }
        }
    }
    cout << "impossible";
    return;

}*/

//dp[i][o][s];

bool determine(){
    n=s.length();
    if(n % 2==1){
        return false;
    }
    if(n==0){
        return true;
    }
    s="."+s;
    dp[0][0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int s1=0;s1<3;s1++){
                if(dp[i][j][s1]){
                    if(s1==0){
                        if(s[i+1]=='('){
                            dp[i+1][j+1][0]=1;
                        }else if(s[i+1]==')' && j>0){
                            dp[i+1][j-1][0]=1;
                        }
                        if(s[i+1]==')'){
                            dp[i+1][j+1][1]=1;
                        }else if(s[i+1]=='(' && j>0){
                            dp[i+1][j-1][1]=1;
                        }
                    }else if(s1==1){
                        if(s[i+1]=='('){
                            dp[i+1][j+1][2]=1;
                        }else if(s[i+1]==')' && j>0){
                            dp[i+1][j-1][2]=1;
                        }
                        if(s[i+1]==')'){
                            dp[i+1][j+1][1]=1;
                        }else if(s[i+1]=='(' && j>0){
                            dp[i+1][j-1][1]=1;
                        }
                    }else{
                        if(s[i+1]=='('){
                            dp[i+1][j+1][2]=1;
                        }else if(s[i+1]==')' && j>0){
                            dp[i+1][j-1][2]=1;
                        }
                    }
                }

            }
        }
    }
    for(int s1=0;s1<3;s1++){
        if(dp[n][0][s1]==1){
            return true;
        }
    }
    return false;
}


int main(){
    freopen("input.txt","r",stdin);
    //string s;
    cin >> s;
    if(determine()){
        cout <<"possible";
    }else{
        cout <<"impossible";
    }

    return 0;
}
