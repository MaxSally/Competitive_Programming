//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0

#include<vector>
#include<iostream>
#include<stdio.h>
    using namespace std;

int n,m;
vector<int> v;

int minN(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

bool checkK(int k){
    int right,sum;
    right=0;
    sum=0;
    int cntM=0;
    while (right < v.size()) {
      sum += v[right];
      if (sum > k) {
        sum = v[right];
        if(sum>k){
            return false;
        }
        cntM++;
      }
      right++;
    }
    if(sum<=k){
        cntM++;
    }
    if(cntM<=m){
        return true;
    }else{
        return false;
    }
}

int findK(int left, int right){
    int mid=(left+right)/2;
    if(left>right){
        return 1e9;
    }
    if(checkK(mid)){
        return minN(findK(left,mid-1),mid);
    }else{
        return findK(mid+1,right);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> n;
        v.resize(n);
        int sumV=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sumV+=v[i];
        }
        cin >> m;
        if(n<m){
            cout << "-1" << endl;
        }else{
            cout << findK(v[0],sumV) << endl;
        }
    }

    return 0;
}
