
#include<stdio.h>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

int v[100010];
int sortv[100010];
int n;


double compare(double a, double b){
    return a<b;

}

double randp(){
    double a=0;
    for(int i=0;i<9;i++){
        a=a/10 + rand()%10;
    }
    return a/10;

}

void generateT(int limit,int num){
    for(int i=0;i<limit;i++){
        double a=randp()*num;
        while((int)a>num){
            a=randp()*num;
        }
        double b=randp();
        if(b>0.5){
            v[i]= (int) a;
        }else{
            v[i]= -(int) a;
        }

    }
}


void print(int limit, int id){
    string t=to_string(id)+".in";
    ofstream os(t);
    for(int i=0;i<limit;i++){
        os << v[i];
        if(i!=limit-1){
            os << " ";
        }
    }
    os.close();
}

void writeDataSum(int id){
    int n,k;
    if(id<=4){
        n=100;
    }else{
        n=100000;
    }
    if(id<=3){
        k=100;
    }else if(id<=7){
        k=1000000;
    }else{
        k=1000000000;
    }
    generateT(n,k);
    if(id==3 || id==7){
        sort(v,v+n,compare);
        if(v[0]*v[1]<v[n-1]*v[n-2]){
            v[0]=-v[0];
            v[1]=-v[1];
            v[n-1]=-v[n-1];
            v[n-2]=-v[n-2];
        }
    }
    print(n,id);
}


int main(){

    for(int test_id=1;test_id<=10;test_id++){
        writeDataSum(test_id);
    }
    return 0;
}
