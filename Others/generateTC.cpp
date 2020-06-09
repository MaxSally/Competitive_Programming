#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include <fstream>
#include<string>
#include<time.h>
using namespace std;

double randp(){
    double a=0;
    for(int i=0;i<9;i++){
        a=a/10 + rand()%10;
    }
    return a/10;
}


void writeDataSum(int id){
    ofstream os("input.in");
    int n = 5000;
    int k = 1;
    os << n <<" " << k << "\n";
    for(int i = 0; i < n; i++){
        int a = (int) randp()*10000;
        while(a < 4000)
            a = randp()*10000;
        a = min(5000, a);
        os << a << " ";
    }
    os << "\n";
}




int main(){
    srand(time(0));
    for(int test_id=1;test_id<=1;test_id++){
        writeDataSum(test_id);
    }
    return 0;
}



