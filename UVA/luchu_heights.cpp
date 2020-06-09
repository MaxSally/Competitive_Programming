//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=316&page=show_problem&problem=1552


#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<functional>
    using namespace std;

int n,q;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("luchu_heights.txt","r",stdin);
    cin >> n;

    vec.resize(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    sort(vec.begin(),vec.end(),compare);
    /*for(int i=0;i<n;i++){
        cout << vec[i] << " ";
    }
    cout << endl;*/
    cin >> q;
    for(int i=0;i<q;i++){
        int height;
        cin >> height;
        vector<int>:: iterator iter;
        iter=lower_bound(vec.begin(),vec.end(),height);
        int first=iter-vec.begin();
        iter=upper_bound(vec.begin(),vec.end(),height);;
        int last=iter-vec.begin();

        if(first-1<0){
            cout << "X ";
        }else {
            cout << vec[first-1] << " ";
        }
        if(last>=n){
            cout << "X" << endl;
        }else {
            cout << vec[last] << endl;
        }
    }
    return 0;
}
