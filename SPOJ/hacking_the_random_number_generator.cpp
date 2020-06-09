//http://www.spoj.com/problems/HACKRNDM/
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
    using namespace std;

int n,k;
int cnt=0;
vector<int> vec;

bool compare(int a, int b){
    return a<b;
}

int binarySearch_first(int left, int right, int value){
    if(left<=right){
        int mid=left+(right-left)/2;
        if(vec[mid]==value && (mid==left || value>vec[mid-1])){
            return mid;
        }else if(value > vec[mid]){
            return binarySearch_first(mid+1,right,value);
        }else {
            return binarySearch_first(left,mid-1,value);
        }

    }
    return -1;
}

int binarySearch_last(int left, int right, int value){
    if(left<=right){
        int mid=left+(right-left)/2;
        if(vec[mid]==value && (mid==right || value<vec[mid+1])){
            return mid;
        }else if(value < vec[mid]){
            return binarySearch_last(left,mid-1,value);
        }else {
            return binarySearch_last(mid+1,right,value);
        }

    }
    return -1;
}


int main(){
    freopen("hacking_the_random_number_generator.txt","r",stdin);
    cin >> n >> k;
    //cout << n << k << endl;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<n;i++){
        int first=binarySearch_first(i,n-1,vec[i]+k);
        int last=binarySearch_last(i,n-1,vec[i]+k);
        if(first!= -1 && last !=-1){
            cnt+=last-first+1;
        }
        //cout << i << " " << cnt << endl;
    }
    cout << cnt;
    return 0;
}
