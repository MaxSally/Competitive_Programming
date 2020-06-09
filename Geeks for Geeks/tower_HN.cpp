//https://practice.geeksforgeeks.org/problems/help-the-old-man/0

#include<iostream>
#include<vector>
#include<stdio.h>
    using namespace std;

int N, no,countN,ansS,ansE;

void towHN(int a, int b, int c,int d){
    if(a==0){
        return;
    }
    towHN(a-1,b,d,c);
    countN++;
    if(no==countN){
        ansS=b;
        ansE=d;
        return;
    }
    towHN(a-1,c,b,d);
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    for(int ii=0;ii<t;ii++){
        cin >> N >> no;
        countN=0;
        towHN(N,1,2,3);
        cout << ansS <<" "<< ansE << endl;
    }
    return 0;
}

