//http://www.spoj.com/problems/OPCPIZZA/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
    using namespace std;

int n,m,except;
vector<int> vec;

bool compare(int a,int b){
    return a<b;
}

bool binarySearch(int left, int right, int x){
    if(left<=right){
        int mid=left+(right-left)/2;
        if(vec[mid]==x){
            if(except==mid){
                return false;
            }
            return true;
        }
        if(x<vec[mid]){
            return binarySearch(left,mid-1,x);
        }
        return binarySearch(mid+1,right,x);
    }
    return false;
}

int main(){
    freopen("pizzaboy.txt","r",stdin);
    int test;
    cin >> test;
    for(int ii=0;ii<test;ii++){
        vec.clear();
        cin >> n >>m;
        int cnt=0;
        vec.resize(n);
        for(int i=0;i<n;i++){
            cin >> vec[i];
        }
        sort(vec.begin(),vec.end(),compare);


        for(int i=0;i<n;i++){
            except=i;
            if(binarySearch(0,n-1,m-vec[i])){

                cnt++;
            }
        }
        cout << cnt/2 << endl;
    }
    return 0;
}
