
#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

class RepeatStringEasy {
	public: int lcs(string s1,string s2, int m, int n){
   if(m==0 || n==0){
       return 0;
   }
   if(dp[m][n]!=-1e9){
       return dp[m][n];
   }
   if(s1[m-1]==s2[n-1]){
       dp[m][n]=1+lcs(s1,s2,m-1,n-1);
       return dp[m][n];
  }else{
      dp[m][n]=max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
      return dp[m][n];
  }
}

int maximalLength(string s){
   int maxN=0;
   int n=s.length();
   for(int ii=1;ii<n;ii++){
       string s1,s2;
       for(int i=0;i<100;i++){
           for(int j=0;j<100;j++){
               dp[i][j]=-1e9;
           }
       }
       for(int i=0;i<ii;i++){
           s1+=s[i];
       }
       for(int i=ii;i<n;i++){
           s2+=s[i];
       }
       maxN=max(maxN,lcs(s1,s2,s1.length(),s2.length())*2);
   }
   return maxN;
}
};

RepeatStringEasy R;

int main () {
    //freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    cout << R.maximalLength(s);
    return 0;
}
