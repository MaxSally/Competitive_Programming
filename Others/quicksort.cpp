#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;


void quickSort(int left, int right, vector<int> &a){
    if(left>=right){
        return;
    }
    int left1=left;
    int right1=right;
    int mid=(left+right)/2;
    while(left1<=right1){
        while(a[left1]<a[mid]){
            left1++;
        }
        while(a[right1]>a[mid]){
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

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quickSort(0,n-1,a);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
