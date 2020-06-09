#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
    using namespace std;

int n,c;

int maxN(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void quickSort(int left, int right, vector<int> &a){
    if(left>=right){
        return;
    }
    int left1=left;
    int right1=right;
    int mid=a[(left+right)/2];
    while(left1<=right1){
        while(a[left1]<mid){
            left1++;
        }
        while(a[right1]>mid){
            right1--;
        }
        if(left1<=right1){
            int x=a[left1];
            a[left1]=a[right1];
            a[right1]=x;
            left1++;
            right1--;
        }
    }
    quickSort(left,right1,a);
    quickSort(left1,right,a);

}

bool checkCow(vector<int> &v,int k){
    int right, sum, left;
    sum=0;
    right=0;
    left=0;
    int cntS=0;
    while(right<v.size()){
        sum=v[right]-v[left];
        if(sum>=k){
            left=right;
            cntS++;
        }
        right++;
    }
    if(v[right]-v[left]>=k){
        cntS++;
    }
    if(cntS>=c){
        return true;
    }
    return false;
}

int findC(int left, int right,vector<int> &v){
    int mid=(left+right)/2;
    //cout << left << " " << mid <<" " << right << endl;
    if(left>right){
        return 0;
    }
    if(checkCow(v,mid)){
        return maxN(findC(mid+1,right,v),mid);
    }else{
        return findC(left,mid-1,v);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> n >> c;
        vector<int> v;
        v.resize(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        quickSort(0,n-1,v);
        cout << findC(v[0],v[n-1]-v[0],v) << endl;
    }
    return 0;
}

