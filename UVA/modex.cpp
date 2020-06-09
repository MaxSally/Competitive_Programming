//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671

#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
    using namespace std;

int power(int x, int y,int n){
    if(y==0){
        return 1;
    }
    if(y==1){
        return x % n;
    }
    int mid=y/2;
    int a=power(x,mid,n);
    if(y % 2 ==0){
        return a*a % n;
    }else{
        return (a*a % n) *x % n;
    }

}

int main(){
    freopen("input.txt","r",stdin);
    int c;
    cin >> c;
    for(int i=0;i<c;i++){
        int x,y,n;
        cin >> x >>y >> n;
        cout << power(x,y,n) << endl;
    }
    cin >> c;
    return 0;
}

